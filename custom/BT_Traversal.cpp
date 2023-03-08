#include <iostream>
#include <vector>
#include <ctime>
#include <functional>
#include <string>
#include <stack>
using std::vector;
using std::stack;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void preorderTraversal(TreeNode *root){
        if(root==nullptr)
            return;
        std::cout<< root->val <<std::ends;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    void inorderTraversal(TreeNode *root){
        if(root==nullptr)
            return;
        inorderTraversal(root->left);
        std::cout<< root->val <<std::ends;
        inorderTraversal(root->right);
    }

    void postorderTraversal(TreeNode *root){
        if(root==nullptr)
            return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout<< root->val <<std::ends;
    }

    // 先序遍历-非递归
    void preorderTraversal_nonRecursion(TreeNode *root){
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* t = stk.top();
            std::cout<< t->val << std::ends;
            stk.pop();
            if(t->right!=nullptr)
                stk.push(t->right);
            if(t->left!=nullptr)
                stk.push(t->left);
        }
    }

    // 中序遍历-非递归
    void inorderTraversal_nonRecursion(TreeNode *root){
        stack<TreeNode*> stk;
        TreeNode* t = root;
        while(!stk.empty()||t!=nullptr){
            if(t!=nullptr){
                stk.push(t);
                t = t->left;
            }else{
                t = stk.top();
                std::cout<< t->val <<std::ends;
                stk.pop();
                t = t->right;
            }
        }
    }

    // 后序遍历-非递归
    void postorderTraversal_nonRecursion(TreeNode *root){
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root);
        while(!stk1.empty()){
            TreeNode* t = stk1.top();
            stk1.pop();
            stk2.push(t);
            if(t->left!=nullptr)
                stk1.push(t->left);
            if(t->right!=nullptr)
                stk1.push(t->right);
        }
        while(!stk2.empty()){
            TreeNode* t = stk2.top();
            stk2.pop();
            std::cout<<t->val<<std::ends;
        }
    }
};
int main()
{
    clock_t begin, end;
    begin = clock();

    Solution s;
    TreeNode t4(4),t5(5),t6(6);
    TreeNode t2(2,&t4,&t5),t3(3,&t6,nullptr);
    TreeNode t1(1,&t2,&t3);

    end = clock();
    std::cout << "Took " << (double)(end - begin) / CLOCKS_PER_SEC << " seconds." << std::endl;
    return 0;
}