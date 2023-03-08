#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using std::queue;
using std::vector;
using std::stack;
/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct Data
{
    bool isValid;
    int min = INT_MAX;
    int max = INT_MIN;
};
class Solution {
public:
    // 非递归
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* t = root;
        long preValue = LONG_MIN;
        while(!stk.empty()||t!=nullptr){
            if(t!=nullptr){
                stk.push(t);
                t = t->left;
            }else{
                t = stk.top();
                stk.pop();
                if(t->val <= preValue){
                    return false;
                }else{
                    preValue = t->val;
                }
                t = t->right;
            }
        }
        return true;
    }

    // 递归
    bool isValidBST2(TreeNode* root) {
        if(root==nullptr)
            return true;
        bool lt = isValidBST2(root->left);
        if(lt && root->val>preValue){
            preValue = root->val;
        }else{
            return false;
        }
        return isValidBST2(root->right);
    }

    bool Fun(TreeNode* root) {
        bool ans = true;
        TreeNode* t = root;
        stack<TreeNode*> stk;
        bool f = false; //是否是第一个
        int last;//上一个数
        while(!stk.empty() || t){
            while(t){
                stk.push(t);
                t = t->left;
            }
            if(!stk.empty()){
                t = stk.top();
                if(!f){
                    f = true;
                }else{
                    if(t->val <= last)
                        return false;
                }
                last = t->val;//记录当前这个数
                stk.pop();
                t = t->right;
            }        
        }
        return ans;
    }

private:
    long preValue = LONG_MIN;
};
/*
Example 1:

Input: root = [2,1,3]
Output: true
Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/
int main(){
    Solution s;
    TreeNode t4(4),t5(5),t6(6);
    TreeNode t2(2,&t4,&t5),t3(3,&t6,nullptr);
    TreeNode t1(1,&t2,&t3);

    return 0;
}