#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using std::priority_queue;
using std::vector;
using std::greater;
/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
*/
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &x : nums) {
            pq.push(x);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    int add(int val) {
        pq.push(val);
        if(pq.size() > K)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
/*
Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4   // 8 5 4
kthLargest.add(5);   // return 5   // 8 5 5
kthLargest.add(10);  // return 5   // 10 8 5
kthLargest.add(9);   // return 8   // 10 9 8
kthLargest.add(4);   // return 8   // 10 9 8
*/
int main(){
    vector <int> nums = {4 , 5 , 8 , 2};
    int k = 3;
    KthLargest stream(k , nums);
    std::cout << stream.add(3) << " ";
    std::cout << stream.add(5) << " ";
    std::cout << stream.add(10) << " ";
    std::cout << stream.add(9) << " ";
    std::cout << stream.add(4) << " ";
    std::cout << std::endl;
    return 0;
}