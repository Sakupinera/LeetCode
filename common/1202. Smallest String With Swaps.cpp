#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <numeric>
using std::string;
using std::vector;
/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.
*/
class UF {
 public:
  UF(int n) : id(n) {
    std::iota(begin(id), end(id), 0);
  }

  void union_(int u, int v) {
    id[find(u)] = find(v);
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
};

struct compare {
  bool operator()(const char a, const char b) {
    return a > b;
  }
};

class Solution {
 public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    string ans;
    UF uf(s.length());
    std::unordered_map<int, std::priority_queue<char, vector<char>, compare>> map;

    for (vector<int>& pair : pairs)
      uf.union_(pair[0], pair[1]);

    for (int i = 0; i < s.length(); ++i)
      map[uf.find(i)].push(s[i]);

    for (int i = 0; i < s.length(); ++i)
      ans += map[uf.find(i)].top(), map[uf.find(i)].pop();

    return ans;
  }
};
/*
Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
*/
int main(){
    Solution s;
    vector<vector<int>> pairs = {{0,3},{1,2},{0,2}};
    string result = s.smallestStringWithSwaps("bcad", pairs);
    std::cout<< result <<std::endl;
    return 0;
}