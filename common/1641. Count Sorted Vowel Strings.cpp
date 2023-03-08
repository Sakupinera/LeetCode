#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using std::vector;
/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
*/
class Solution {
#pragma region MyCode

// public:
//     int countVowelStrings(int n) {
//         result = 0;
//         backtrace(n,1,0);
//         return result;
//     }
// private:
//     int result;

//     void backtrace(int &n, int curDepth, int vowel){
//         if(curDepth > n){
//             result+=1;
//             return;
//         }
//         for(int i=vowel;i<5;i++){
//             backtrace(n, curDepth+1, i);
//         }
//     }
#pragma endregion
public:
  int countVowelStrings(int n) {
    // dp[0] := # of lexicographically sorted strings ends with 'a'
    // dp[1] := # of lexicographically sorted strings ends with 'e'
    // dp[2] := # of lexicographically sorted strings ends with 'i'
    // dp[3] := # of lexicographically sorted strings ends with 'o'
    // dp[4] := # of lexicographically sorted strings ends with 'u'
    vector<int> dp(5, 1);

    for (int i = 2; i <= n; ++i) {
      vector<int> newDp(5);
      for (int j = 0; j < 5; ++j)
        for (int k = 0; k <= j; ++k)
          newDp[j] += dp[k];
      dp = move(newDp);
    }

    return std::accumulate(begin(dp), end(dp), 0);
  }
};
/*
Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045
*/
int main(){
    Solution s;
    std::cout<<s.countVowelStrings(2)<<std::endl;
    return 0;
}