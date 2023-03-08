#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>
#include <map>
using std::vector;
using std::multiset;
using std::priority_queue;
using std::pair;
/*
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.
*/
struct cmp{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        return p1.first < p2.first;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        multiset<int> ms(nums.begin(),nums.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(auto iter=nums.begin();iter!=nums.end();iter+=ms.count(*iter)){
            pq.push(std::make_pair(ms.count(*iter),*iter));
        }
        for(int i=0; i<k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
/*
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]
*/
int main(){
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> vec = s.topKFrequent(nums, 2);
    for(auto e: vec){
        std::cout<< e <<std::endl;
    }

    return 0;
}