#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
/*
Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 10^9 + 7.
*/
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int res = 0, n = arr.size(), M = 1e9 + 7;
        unordered_map<int, int> numCnt;
        for (int i = 0; i < n; ++i) {
            res = (res + numCnt[target - arr[i]]) % M;
            for (int j = 0; j < i; ++j) {
                int sum = arr[i] + arr[j];
                ++numCnt[sum];
            }
        }
        return res;
    }
};
/*
Example 1:

Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
Example 2:

Input: arr = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
*/
int main(){
    Solution s;
    vector<int> vec = {1,1,2,2,3,3,4,4,5,5};
    int target = 8;
    std::cout<< s.threeSumMulti(vec, target) <<std::endl;

    return 0;
}