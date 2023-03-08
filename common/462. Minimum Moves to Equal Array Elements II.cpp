#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
using std::vector;
/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int bi=0,ei=nums.size()-1;
        while(bi<ei){
            bi++;
            ei--;
        }
        int medium = (nums[bi] + nums[ei])/2;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            count += std::abs(nums[i]-medium);
        }
        return count;
    }
};
/*
Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Example 2:

Input: nums = [1,10,2,9]
Output: 16
*/
int main(){
    Solution s;
    vector<int> vec{1,0,0,8,6};     // 0 1 1 7 5
    std::cout<< s.minMoves2(vec) << std::endl;
    return 0;
}