#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::stack;
/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.
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
// void inorderTraversal(TreeNode* root, vector<TreeNode*>& inorderVec){
//     if(!root)
//         return;
//     inorderTraversal(root->left, inorderVec);
//     inorderVec.push_back(root);
//     inorderTraversal(root->right, inorderVec);
// }
// class BSTIterator {
// public:
//     BSTIterator(TreeNode* root) {
//         inorderTraversal(root, inorderVec);
//         curIndex = 0;
//     }
    
//     int next() {
//         return inorderVec[curIndex++]->val;
//     }
    
//     bool hasNext() {
//         if(curIndex < inorderVec.size())
//             return true;
//         else
//             return false;
//     }
// private:
//     vector<TreeNode*> inorderVec;
//     int curIndex;
// };
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *n = s.top();
        s.pop();
        int res = n->val;
        if (n->right) {
            n = n->right;
            while (n) {
                s.push(n);
                n = n->left;
            }
        }
        return res;
    }
private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main(){
    TreeNode t31(9),t32(20);
    TreeNode t21(3),t22(15,&t31,&t32);
    TreeNode root(7,&t21,&t22);
    BSTIterator bstIter(&root);
    return 0;
}