#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using std::vector;
/*
You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.
*/
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        std::sort(horizontalCuts.begin(),horizontalCuts.end());
        std::sort(verticalCuts.begin(),verticalCuts.end());
        vector<int> horizontalLines(horizontalCuts);
        int hMaxGap = horizontalCuts[0], vMaxGap = verticalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++){
            hMaxGap = std::max(hMaxGap, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        hMaxGap = std::max(hMaxGap, h-horizontalCuts[horizontalCuts.size()-1]);
        for(int j=1;j<verticalCuts.size();j++){
            vMaxGap = std::max(vMaxGap, verticalCuts[j]-verticalCuts[j-1]);
        }
        vMaxGap = std::max(vMaxGap, w-verticalCuts[verticalCuts.size()-1]);
        return long(hMaxGap)*long(vMaxGap)%(int)(std::pow(10,9)+7);
    }

};
/*
Example 1:

Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
Example 2:

Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9
*/
int main(){
    Solution s;
    int h=5,w=4;
    vector<int> horizontalCuts = {1,2,4};
    vector<int> verticalCuts = {1,3};
    std::cout<< s.maxArea(h,w,horizontalCuts,verticalCuts);
    return 0;
}