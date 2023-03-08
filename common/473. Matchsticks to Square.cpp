#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
/*
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.
*/
class Solution
{
public:
    bool solve(int idx, vector<int> &sums, int target, vector<int> &nums)
    {
        if (idx >= nums.size())
        {
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == target;
        }
        for (int i = 0; i < 4; i++)
        {
            if (sums[i] + nums[idx] > target)
                continue;
            sums[i] += nums[idx];
            if (solve(idx + 1, sums, target, nums))
                return true;
            sums[i] -= nums[idx];
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        if (matchsticks.size() == 0)
            return false;
        int x = 0;
        for (int i = 0; i < matchsticks.size(); i++)
        {
            x += matchsticks[i];
        }
        if (x % 4)
            return false;
        std::sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sum(4);
        return solve(0, sum, x / 4, matchsticks);
    }
};
/*
Example 1:

Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
*/
int main()
{
    Solution s;
    vector<int> vec = {1,1,2,2,2};
    std::cout << std::boolalpha << s.makesquare(vec) << std::endl;
    return 0;
}