#include <iostream>
#include <vector>
using std::vector;
/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if(grid.empty()==true)
            return 0;
        
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> searched(m,vector<bool>(n,false));
        
        int count =0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&!searched[i][j]){
                    count++;
                    dfs(i,j,grid,searched);
                }
            }
        }

        return count;
    }

    void dfs(int i,int j,vector<vector<char>> &grid, vector<vector<bool>> &searched)
    {
        if(i<0||i>=searched.size()||j<0||j>=searched[0].size())
            return;
        
        if(searched[i][j] || grid[i][j]=='0')
            return;

        searched[i][j]=true;

        dfs(i+1,j,grid,searched);
        dfs(i-1,j,grid,searched);
        dfs(i,j-1,grid,searched);
        dfs(i,j+1,grid,searched);
    }
};
/*
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/
int main()
{
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    std::cout << s.numIslands(grid) << std::endl;
    return 0;
}