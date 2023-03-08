#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
*/
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        auto dist = [](const vector<int>& pi, const vector<int>& pj) {
            return abs(pi[0] - pj[0]) + abs(pi[1] - pj[1]);
        };
        vector<int> ds(n, INT_MAX);  
        for (int i = 1; i < n; ++i)
            ds[i] = dist(points[0], points[i]);
        
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            auto it = std::min_element(begin(ds), end(ds));
            const int v = std::distance(begin(ds), it);
            ans += ds[v];      
            ds[v] = INT_MAX; // done
            for (int i = 0; i < n; ++i) {
                if (ds[i] == INT_MAX) continue;
                ds[i] = std::min(ds[i], dist(points[i], points[v]));
            }        
        }
        return ans;
    }
};
/*
Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
*/
int main(){
    Solution s;
    vector<vector<int>> points(5, vector<int>(2, 0));
    points[1][0] = 2, points[1][1] = 2;
    points[2][0] = 3, points[2][1] = 10;
    points[3][0] = 5, points[3][1] = 2;
    points[4][0] = 7, points[4][1] = 0;
    std::cout << s.minCostConnectPoints(points) << std::endl;
    return 0;
}