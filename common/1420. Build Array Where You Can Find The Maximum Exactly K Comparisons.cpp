#include<iostream>
#include<vector>
/*
You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:
*/
int GetMaximumIndex(std::vector<int> arr)
{
    int maximumValue = -1;
    int maximumIndex = -1;
    int searchCost = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(maximumValue < arr[i]){
            maximumValue = arr[i];
            maximumIndex = i;
            searchCost += 1;
        }
    }
    return maximumIndex;
}
/*
You should build the array arr which has the following properties:

    + arr has exactly n integers.
    + 1 <= arr[i] <= m where (0 <= i < n).
    + After applying the mentioned algorithm to arr, the value search_cost is equal to k.

Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.
*/
class Solution {
    typedef long long LL;
    LL dp[51][101][51] = {};
public:
    /// @brief 
    /// @param n 表示数组元素的个数
    /// @param m 表示数组的最大值为多少
    /// @param k 表示后面的数比前面大的数可以有几个
    /// @return 返回满足条件的数组的个数
    int numOfArrays(int n, int m, int k) {
        int mod = 1e9+7;
        for (int i = 0; i <= m; ++i) 
            dp[1][i][1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int t = 1; t <= k; ++t) {
                    LL s = 0;
                    s = (s + j * dp[i - 1][j][t]) % mod;
                    for (int x = 1; x < j; ++x) 
                        s = (s + dp[i - 1][x][t - 1]) % mod;
                    dp[i][j][t] = (dp[i][j][t] + s) % mod;
                }
            }
        }
        LL ans = 0;
        for (int i = 1; i <= m; ++i) 
            ans = (ans + dp[n][i][k]) % mod;
        return ans;
    }
};
/*
Example 1:

Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
Example 2:

Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisfy the mentioned conditions.
Example 3:

Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
*/
int main()
{


    return 0;
}