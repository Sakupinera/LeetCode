#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.
*/
class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int m = unique(nums.begin(), nums.end()) - nums.begin();
        // int n = nums.size();
        // int ans = n;
        // for (int i = 0; i < m; ++i) {
        //     int j = upper_bound(nums.begin() + i, nums.begin() + m, nums[i] + n - 1) - nums.begin();
        //     ans = min(ans, n - (j - i));
        // }
        // return ans;

        sort(nums.begin(), nums.end());
        int m = unique(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        int ans = n;
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < m && nums[j] - nums[i] <= n - 1) {
                ++j;
            }
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};
/*
Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
Example 3:

Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.
*/
int main(){

    return 0;
}