#include <iostream>
#include <vector>
using std::vector;
/*
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.
*/
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        int max = 0;
        for (int num : nums)
        {
            max = std::max(max, num);
        }
        vector<int> val(max + 1, 0);
        for (int num : nums)
            val[num]++;
        vector<int> dp(max + 1, 0);
        for (int i = 1; i < dp.size(); i++)
        {
            dp[i] = std::max(dp[i - 1], (i > 1 ? dp[i - 2] : 0) + i * val[i]);
        }
        return dp[max];
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    std::cout << solution.deleteAndEarn(nums) << std::endl;
    return 0;
}