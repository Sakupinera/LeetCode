#include <iostream>

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        
    }
};
int main(){
    Solution solution;

    ListNode* node1_2 = new ListNode(4);
    ListNode* node1_1 = new ListNode(2,node1_2);
    ListNode* node1_0 = new ListNode(1,node1_1);

    ListNode* node2_2 = new ListNode(4);
    ListNode* node2_1 = new ListNode(3,node2_2);
    ListNode* node2_0 = new ListNode(1,node2_1);

    ListNode* list1 = node1_0;  //  1,2,4
    ListNode* list2 = node2_0;  //  1,3,4

    ListNode* p = solution.mergeTwoLists(list1,list2);

    while(p!=nullptr){
        std::cout<< p->val <<std::ends;
        p = p->next;
    }

    return 0;
}