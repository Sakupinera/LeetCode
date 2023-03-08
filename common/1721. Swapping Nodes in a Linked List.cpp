#include <iostream>
#include <vector>
using std::vector;
/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<ListNode *> vec;
        ListNode *index = head;
        int length = 0;
        while (index != nullptr)
        {
            vec.push_back(index);
            index = index->next;
            length++;
        }
        int tmepVal = vec[k-1]->val;
        vec[k-1]->val = vec[length-k]->val;
        vec[length-k]->val = tmepVal;

        return head;
    }
};
/*
Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
*/
int main()
{
    Solution s;
    ListNode n1(5, nullptr);
    ListNode n2(4, &n1);
    ListNode n3(3, &n2);
    ListNode n4(2, &n3);
    ListNode n5(1, &n4);
    s.swapNodes(&n5, 2);
    ListNode* index = &n5;
    while(index!=nullptr){
        std::cout<< index->val <<std::endl;
        index = index->next;
    }
    return 0;
}