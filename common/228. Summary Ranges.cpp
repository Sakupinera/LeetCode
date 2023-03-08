#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
/*
You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
*/
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        string str = "";
        vector<string> sr;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                str = std::to_string(nums[i]);
            }
            if (i + 1 < nums.size())
            {
                if (nums[i + 1] != nums[i] + 1 && count != 0)
                {
                    str += "->" + std::to_string(nums[i]);
                    sr.push_back(str);
                    count = 0;
                    continue;
                }
                else if (nums[i + 1] != nums[i] + 1 && count == 0)
                {
                    sr.push_back(str);
                    count = 0;
                    continue;
                }
            }else{
                if(count==0){
                    str = std::to_string(nums[i]);
                    sr.push_back(str);
                }else{
                    str += "->" + std::to_string(nums[i]);
                    sr.push_back(str);
                }
            }
            count++;
        }
        return sr;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
    // vector<int> nums = {0,1,2,4,5,7};
    vector<string> sr = s.summaryRanges(nums);
    for (auto iter = sr.begin(); iter != sr.end(); iter++)
    {
        std::cout << *iter << std::ends;
    }
    std::cout << std::endl;
    return 0;
}