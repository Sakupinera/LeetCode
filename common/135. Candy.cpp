#include <iostream>
#include <vector>
#include <numeric>
using std::vector;
/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
*/
class Solution
{
public:
    // int candy(vector<int> &ratings)
    // {
    //     if (ratings.size() <= 1)
    //         return 1;
    //     vector<int> candyVec(ratings.size(), 1);
    //     int count = 0;
    //     for (int i = 1; i < ratings.size(); i++)
    //     {
    //         if (ratings[i - 1] > ratings[i])
    //         {
    //             for(int j=0;j<=count;j++){
    //                 if(candyVec[i-1-j] <= candyVec[i-j])
    //                     candyVec[i-1-j] = candyVec[i-j] + 1;
    //             }
    //             count++;
    //         }
    //         else if (ratings[i - 1] < ratings[i])
    //         {
    //             candyVec[i] = candyVec[i - 1] + 1;
    //             count = 0;
    //         }else{
    //             count = 0;
    //         }
    //     }
    //     return std::accumulate(candyVec.begin(), candyVec.end(), 0);
    // }

    int candy(vector<int> &ratings)
    {
        if(ratings.size() == 0)
            return 0;
        vector<int> count(ratings.size());
        count[0] = 1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i] > ratings[i-1]){
                count[i] = count[i-1] + 1;
            }else{
                count[i] = 1;
            }
        }
        int res = count[ratings.size()-1];

        for(int i=ratings.size()-1; i >0;i--){
            if(ratings[i-1] > ratings[i] && count[i-1] <= count[i]){
                count[i-1] = count[i] + 1;
            }
            res += count[i-1];
        }

        return res;
    }
};
/*
Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
*/
int main()
{
    Solution s;
    vector<int> vec = {1,3,4,5,2};  // 9
    std::cout << s.candy(vec) << std::endl; // 11
    return 0;
}