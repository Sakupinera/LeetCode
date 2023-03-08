#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
/*
You are given the root of a binary search tree (BST), 
where the values of exactly two nodes of the tree were swapped by mistake.
Recover the tree without changing its structure.
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
// class Solution {
// public:
//     void recoverTree(TreeNode* root) {
//         vector<TreeNode*> list;
//         vector<int> vals;
//         inorder(root, list, vals);
//         std::sort(vals.begin(), vals.end());
//         for (int i = 0; i < list.size(); ++i) {
//             list[i]->val = vals[i];
//         }
//     }
//     void inorder(TreeNode* root, vector<TreeNode*>& list, vector<int>& vals) {
//         if (!root) return;
//         inorder(root->left, list, vals);
//         list.push_back(root);
//         vals.push_back(root->val);
//         inorder(root->right, list, vals);
//     }
// };
// Now O(1) space complexity
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *cur = root, *pre = nullptr ;
        while (cur) {
            if (cur->left){
                TreeNode *p = cur->left;
                while (p->right && p->right != cur) p = p->right;
                if (!p->right) {
                    p->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    p->right = NULL;
                }  
            }
            if (pre && cur->val < pre->val){
              if (!first) first = pre;
              second = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        std::swap(first->val, second->val);
    }
};
/*
Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
*/
int main(){
    Solution s;
    TreeNode t3(2);
    TreeNode t21(1),t22(4,&t3,nullptr);
    TreeNode t1(3,&t21,&t22);
    s.recoverTree(&t1);
    return 0;
}