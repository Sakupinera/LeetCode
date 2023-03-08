#include <iostream>
#include <vector>
using std::vector;
/*
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.
*/
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        k %= m * n;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int index = (i * n + j + k) % (m * n);
                int x = index / n;
                int y = index % n;
                ans[x][y] = grid[i][j];
            }

        return ans;
    }
};
/*
Example 1:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]

Example 2:
Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

Example 3:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]
*/
int main(){
    Solution s;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 1;
    vector<vector<int>> result = s.shiftGrid(grid, k);
    for(auto vec: result){
        for(auto i: vec){
            std::cout<< i <<std::ends;
        }
        std::cout<<std::endl;
    }
    return 0;
}