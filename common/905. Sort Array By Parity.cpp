#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using std::vector;
/*
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>::iterator itb = nums.begin();
        vector<int>::iterator ite = nums.end();
        ite--;
        while(ite-itb>0){
            while(*itb % 2 == 0 && itb!=ite){
                itb++;
            }
            while(*ite % 2 == 1 && itb!=ite){
                ite--;
            }
            std::swap(*itb,*ite);
            itb++;
            ite--;
        }
        return nums;
    }
};
/*
Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
*/
int main(){
    clock_t start,end;
    start = clock();

    Solution s;
    vector<int> nums = {0,2};
    vector<int> result = s.sortArrayByParity(nums);
    for(auto e: result){
        std::cout<< e << std::ends;
    }
    std::cout<<std::endl;

    end = clock();
    std::cout<<"Took "<< (double)(end-start)/CLOCKS_PER_SEC << " seconds."<<std::endl;
    return 0;
}