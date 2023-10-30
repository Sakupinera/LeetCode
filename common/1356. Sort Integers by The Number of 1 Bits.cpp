#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.
*/
class Solution {
public:
    int count_set_bit(int x){
        int bits = 0;
        while(x != 0){
            bits += x&1;
            x >>= 1;
        }
        return bits;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> sorted;
        for(int e : arr){
            //first sort by set bit count and then by itself
            //* 100000 because the max of arr is 10000
            sorted.push_back(count_set_bit(e) * 100000 + e);
        }
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < sorted.size(); i++){
            sorted[i] = sorted[i]%100000;
        }
        
        return sorted;
    }
};
/*
Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 104
*/
int main(){

    return 0;
}