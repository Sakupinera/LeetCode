#include <iostream>
/*
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.
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
    // No cleanup -> memory leak 
    // TreeNode* trimBST(TreeNode* root, int low, int high) {
    //     if(!root) return nullptr;
    //     // val not in range, return the left/right subtrees
    //     if(root->val < low) return trimBST(root->right, low, high);
    //     if(root->val > high) return trimBST(root->left, low, high);
    //     // val in [L, R], recusively trim left/right subtrees
    //     root->left = trimBST(root->left, low, high);
    //     root->right = trimBST(root->right, low, high);
    //     return root;
    // }

    // With cleanup -> no memory leak
    TreeNode*& trimBST(TreeNode*& root, int L, int R) {
        if(!root) return root;
        
        if(root->val < L) {            
            auto& result = trimBST(root->right, L, R);
            deleteTree(root->left);
            delete root;
            root=nullptr;
            return result;
        } else if(root->val > R) {
            auto& result = trimBST(root->left, L, R);
            deleteTree(root->right);
            delete root;
            root=nullptr;
            return result;
        } else {
            // recusively trim left/right subtrees
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
    }
    
    void deleteTree(TreeNode* &root) {
        if(!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root=nullptr;
    }
};
void PrintTree(TreeNode* root) {
    if(!root) {
        std::cout<<"null ";
        return;
    };
    if(!root->left && !root->right) {
        std::cout<<root->val<<" ";
    } else {
        std::cout<<root->val<<" ";
        PrintTree(root->left);
        PrintTree(root->right);
    }
}
/*
Example 1:

Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
Example 2:

Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]
*/
int main(){
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);
    PrintTree(root);
    std::cout<<std::endl;
    
    TreeNode* t = Solution().trimBST(root, 1, 2);
    PrintTree(t);
    std::cout<<std::endl;
 
    // Original root was deleted
    PrintTree(root);
    std::cout<<std::endl;
    
    return 0;
}