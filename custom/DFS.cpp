#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int depth = 0;
int dfs(vector<vector<int>>& vec, vector<bool>& visited, int node){
    visited[node] = true;
    for(int i=0;i<vec[node].size();i++){
        if(!visited[vec[node][i]]){
            depth = max(depth, dfs(vec, visited, vec[node][i]));
            depth++;
        }
    }
    return depth;
}
int main(){
    vector<vector<int>> vec = {
        {1,2},
        {2,3,5},
        {0,1,3},
        {2,4,5},
        {1,3,5},
        {1,3,4}
    };
    vector<bool> visited(6,false);
    cout<< dfs(vec,visited,0) <<endl;
    return 0;
}