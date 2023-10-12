#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.
*/
class Solution {
public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>>& flowers, std::vector<int>& people) {
        vector<int> ans;
        vector<int> starts;
        vector<int> ends;

        for (const vector<int>& flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        for (const int p : people) {
            const int started = upper_bound(starts.begin(), starts.end(), p) - starts.begin();
            const int ended = lower_bound(ends.begin(), ends.end(), p) - ends.begin();
            ans.push_back(started - ended);
        }

        return ans;
    }
};
/*
Example 1:


Input: flowers = [[1,6],[3,7],[9,12],[4,13]], poeple = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
Example 2:


Input: flowers = [[1,10],[3,3]], poeple = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
*/
int main(){
    return 0;
}