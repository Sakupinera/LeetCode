#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal 
of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *proot = nullptr;
        proot = constructTree(proot,preorder,inorder);
        return proot;
    }
private:
    TreeNode* constructTree(TreeNode *node,vector<int> preorder, vector<int> inorder){
        if(preorder.size()>0){
            node = new TreeNode(preorder[0]);
        }else{
            return nullptr;
        }
        std::vector<int>::iterator vit = std::find(inorder.begin(),inorder.end(),preorder[0]);
        vector<int> inorder_c1 = vector<int>(inorder.begin(),vit);
        vector<int> inorder_c2 = vector<int>(vit+1,inorder.end());
        node->left = constructTree(node->left,vector<int>(preorder.begin()+1,preorder.begin()+1+inorder_c1.size()),
                inorder_c1);
        node->right = constructTree(node->right,vector<int>(preorder.begin()+1+inorder_c1.size(),preorder.end()),
                inorder_c2);
        return node;
    }
};
/*
Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/
int main(){
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode *root = s.buildTree(preorder,inorder);
    return 0;
}