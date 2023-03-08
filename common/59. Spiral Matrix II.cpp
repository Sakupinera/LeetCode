#include <iostream>
#include <vector>
using std::vector;
/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        #pragma region 解法一
        // vector<vector<int>> res(n, vector<int>(n));
        // int val = 1, p = n;
        // for (int i = 0; i < n / 2; ++i, p -= 2) {
        //     for (int col = i; col < i + p; ++col)
        //         res[i][col] = val++;
        //     for (int row = i + 1; row < i + p; ++row)
        //         res[row][i + p - 1] = val++;
        //     for (int col = i + p - 2; col >= i; --col)
        //         res[i + p - 1][col] = val++;
        //     for (int row = i + p - 2; row > i; --row)    
        //         res[row][i] = val++;
        // }
        // if (n % 2 != 0) res[n / 2][n / 2] = val;
        // return res;
        #pragma endregion

        vector<vector<int>> res(n, vector<int>(n));
        int up = 0, down = n - 1, left = 0, right = n - 1, val = 1;
        while (true) {
            for (int j = left; j <= right; ++j) res[up][j] = val++;
            if (++up > down) break;
            for (int i = up; i <= down; ++i) res[i][right] = val++;
            if (--right < left) break;
            for (int j = right; j >= left; --j) res[down][j] = val++;
            if (--down < up) break;
            for (int i = down; i >= up; --i) res[i][left] = val++;
            if (++left > right) break;
        }
        return res;
    }
};
/*
Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
*/
int main(){
    Solution s;
    vector<vector<int>> vec = s.generateMatrix(3);
    for(auto v: vec){
        for(auto e: v){
            std::cout<< e <<std::ends;
        }
        std::cout<<std::endl;
    }
    return 0;
}