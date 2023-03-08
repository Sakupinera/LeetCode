#include <iostream>
#include <vector>
using std::vector;
// Definition for a binary tree node.
/*
Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.
*/
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
    vector<int> result;
public:
    vector<int> rightSideView(TreeNode* root) {
        TreeNode *index = root;
        search(index,0);
        return result;
    }

    void search(TreeNode* node, int depth){
        if(node==nullptr)
            return;
        while(result.size() < depth+1){
            result.push_back(node->val);
        }
        result[depth] = node->val;
        if(node!=nullptr){
            search(node->left,depth+1);
            search(node->right,depth+1);
        }
    }
};
/*
Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
*/
int main(){
    Solution s;
    TreeNode t4(4),t5(5);
    TreeNode t2(2,nullptr,&t5);
    TreeNode t3(3,nullptr,&t4);
    TreeNode t1(1,&t2,&t3);
    vector<int> vec = s.rightSideView(&t1);
    for(auto e : vec){
        std::cout << e << " " << std::endl;
    }
    return 0;
}