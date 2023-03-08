#include <iostream>
#include <vector>
using std::vector;
/*
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.
*/
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        int dp[n] = {0};
        for (int i = 2; i < n; i++)
        {
            if ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2]))
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = 0;
            sum += dp[i];
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 7, 8, 9};
    std::cout << solution.numberOfArithmeticSlices(nums) << std::endl;
    return 0;
}