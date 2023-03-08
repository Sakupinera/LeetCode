#include <iostream>
#include <vector>
#include <map>
using std::vector;
using std::map;
/*
Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto num: nums){
            numCountMap[num] = 0;
        }
        for(auto num: nums){
            numCountMap[num]+=1;
        }
        dfs(nums);
        return result;
    }

    void dfs(const vector<int>& nums){
        if(nums.size()==curVec.size()){
            result.push_back(curVec);
            return;
        }
        for(auto pair: numCountMap){
            if(pair.second>0){
                curVec.push_back(pair.first);
                numCountMap[pair.first]-=1;
                dfs(nums);
                curVec.pop_back();
                numCountMap[pair.first]+=1;
            }
        }
    }

private:
    vector<vector<int>> result;
    vector<int> curVec;
    map<int, int> numCountMap;
};
/*
Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
int main(){
    Solution s;
    vector<int> nums = {1,1,2};
    vector<vector<int>> result = s.permuteUnique(nums);
    for(auto vec: result){
        for(auto e:vec){
            std::cout<< e <<std::ends;
        }
        std::cout<<std::endl;
    }
    return 0;
}
