#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using std::vector;
using std::map;
/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
ans[i] is the number of 1's in the binary representation of i.
*/
class Solution
{
public:
    vector<int> countBits(int n)
    {
        int t = floor(log(n) / log(2));
        vector<int> refv = vector<int>(t + 1, 0);
        vector<int> output_v;
        map<int,int> _map;
        for (int i = 0; i < refv.size(); i++)
        {
            refv[i] = pow(2, i);
        }
        for (int i = 0; i <= n; i++)
        {
            output_v.push_back(function(i, refv, _map));
        }
        return output_v;
    }

    int function(int num, const vector<int> &refv, map<int,int>& _map)
    {
        int count = 0;
        if (num == 0)
            return count;
        auto f = [&refv, &count](int num) -> int
        {
            int index = -1;
            while (num >= refv[index + 1])
            {
                if (num == refv[index++ + 1])
                    break;
            }
            count++;
            return index;
        };
        int begin_i = f(num);
        _map[num] = begin_i;
        int temp = num;
        int cur_num = num;
        int delta = num - refv[begin_i];
        while (cur_num != num)
        {
            temp -= delta;
            if(_map.find(temp)==_map.end()){
                int index = f(temp);
                _map[temp] = index; 
                delta = refv[index];
            }else{
                delta = refv[_map[temp]];
                count++; 
            }
            cur_num += delta;
        }
        return count;
    }
};
// class Solution {
// public:
//     vector<int> countBits(int n)
//     {
//         vector<int> ans(n+1, 0);
        
//         for(int i = 1; i < n+1; i++){
//             ans[i] = ans[i/2] + i%2;
//         }
        
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> ans;
//         for(int i=0;i<=num;i++){
//             ans.push_back(__builtin_popcount(i));
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> ans;
//         for(int i=0;i<=num;i++){
//             int count = 0;
//             int j = i;
//             while(j!=0){
//                 count+=j%2;
//                 j/=2;
//             }
//             ans.push_back(count);
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> ret(num+1, 0);
//         for (int i = 1; i <= num; ++i)
//             ret[i] = ret[i&(i-1)] + 1; //by @fengcc
//             // ret[i] = ret[i/2] + i % 2; //by @sijiec
//         return ret;
//     }
// };
int main()
{
    int n = 2;
    Solution s;
    vector<int> result = s.countBits(n);
    for (auto iter = result.begin(); iter != result.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
    return 0;
}