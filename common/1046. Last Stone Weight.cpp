#include <iostream>
#include <vector>
#include <set>
using std::vector;
using std::multiset;
/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 0)
            return 0;
        multiset<int> s(stones.begin(), stones.end());
        // std::cout<< *(--s.end()) <<std::endl;
        while(s.size()>1){
            auto pi2 = s.end();
            int i1 = *(--pi2);
            auto pi1 = pi2;
            int i2 = *(--pi2);
            int newValue = i1 - i2;
            s.erase(pi1);
            s.erase(pi2);
            s.insert(newValue);
        }
        return *s.begin();
    }
};
/*
Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
Example 2:

Input: stones = [1]
Output: 1
*/
int main(){
    Solution s;
    vector<int> stones = {4,6,4,10};
    std::cout<< s.lastStoneWeight(stones) <<std::endl;
    return 0;
}