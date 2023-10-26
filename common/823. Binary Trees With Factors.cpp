#include <iostream>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;
/*
Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.
*/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        constexpr int kMod = 1'000'000'007;
        const int n = arr.size();
        // dp[i] := # of binary trees with arr[i] as root
        vector<long> dp(n, 1);
        unordered_map<int, int> numToIndex;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; ++i)
            numToIndex[arr[i]] = i;

        for (int i = 0; i < n; ++i)  // arr[i] is root
        for (int j = 0; j < i; ++j)
            if (arr[i] % arr[j] == 0) {  // arr[j] is left subtree
                const int right = arr[i] / arr[j];
                if (const auto it = numToIndex.find(right); it != numToIndex.cend()) {
                    dp[i] += dp[j] * dp[it->second];
                    dp[i] %= kMod;
                }
            }

        return accumulate(dp.begin(), dp.end(), 0L) % kMod;
    }
};
/*
Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].

Constraints:

1 <= arr.length <= 1000
2 <= arr[i] <= 109
All the values of arr are unique.
*/
int main()
{
    vector<int> arr{2,4};

    Solution s;
    s.numFactoredBinaryTrees(arr);

    return 0;
}