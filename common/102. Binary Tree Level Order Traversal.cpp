#include <iostream>
#include <vector>
using std::vector;
/*
Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).
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
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)
            return {};
        transform(0,root);
        return result;
    }

    void transform(int depth, TreeNode* node){
        if(node==nullptr)
            return;
        if(result.size() < depth + 1){
            result.push_back(vector<int>());
        }
        if(node!=nullptr){
            transform(depth+1,node->left);
            result[depth].push_back(node->val);
            transform(depth+1,node->right);
        }
    }
};
/*
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
*/
int main(){
    Solution s;
    TreeNode t4(15),t5(7);
    TreeNode t2(9),t3(20,&t4,&t5);
    TreeNode t1(3,&t2,&t3);
    vector<vector<int>> result = s.levelOrder(&t1);
    for(auto vec: result){
        for(auto e: vec){
            std::cout<< e << std::ends;
        }
        std::cout<<std::endl;
    }
    return 0;
}