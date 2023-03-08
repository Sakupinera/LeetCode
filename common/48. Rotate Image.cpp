#include <iostream>
#include <vector>
using std::vector;
/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for(int i=0;i<matrix.size()/2;i++){
            for(int j=0;j<matrix[0].size();j++){
                std::swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                std::swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
/*
Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/
int main(){
    Solution s;
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    s.rotate(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            std::cout<< matrix[i][j]<<std::ends;
        }
        std::cout<<std::endl;
    }
    return 0;
}