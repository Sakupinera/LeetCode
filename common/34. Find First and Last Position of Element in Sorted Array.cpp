#include <iostream>
#include <vector>
/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n == 0) return {-1, -1};
        
        int left = 0, right = n-1;
        
        //find left boundary
        while(left <= right){
            int mid = (left+right) >> 1;
            // cout << left << ", " << mid << ", " << right << endl;
            
            if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        if(left >= n || nums[left] != target){
            return {-1, -1};
        }
        
        std::vector<int> ans = {left};
        
        //find right boundary
        left = 0;
        right = n-1;
        while(left <= right){
            int mid = (left+right) >> 1;
            // cout << left << ", " << mid << ", " << right << endl;
            
            if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        
        ans.push_back(right);
        
        return ans;
    }
};
/*
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/
int main()
{
    return 0;
}