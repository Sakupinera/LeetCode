#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using std::vector;
/*
You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // int count = 0;
        // std::sort(begin(nums),end(nums));
        // int b = 0;
        // int e = nums.size()-1;
        // while(b < e){
        //     const int s = nums[b] + nums[e];
        //     if(s == k){
        //         count++;
        //         b++;
        //         e--;
        //     }else if(s < k){
        //         b++;
        //     }else{
        //         e--;
        //     }
        // }
        // return count;

        std::unordered_map<int, int> m;
        int ans = 0;
        for (int x : nums) ++m[x];
        for (int x : nums) {      
            if (m[x] < 1 || m[k - x] < 1 + (x + x == k)) continue;
            --m[x];
            --m[k - x];
            ++ans;      
        }
        return ans;
    }
};
/*
Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
*/
int main(){
    Solution s;
    vector<int> vec = {1,2,3,4};
    std::cout << s.maxOperations(vec,5) <<std::endl;
    return 0;
}