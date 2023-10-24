#include <iostream>
#include <vector>
#include <stack>
#include <list>
/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
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
    std::vector<int> largestValues(TreeNode* root) 
    {
        std::stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        std::vector<int> ansVector;
        while(nodeStack.size() > 0){
            long levelMaxValue = INT64_MIN;
            std::stack<TreeNode*> copyNodeStack(nodeStack);
            std::list<TreeNode*> poppedNodeList;
            while(copyNodeStack.size() > 0){
                auto node = copyNodeStack.top();
                copyNodeStack.pop();
                nodeStack.pop();
                if(node != nullptr && node->val > levelMaxValue){
                    levelMaxValue = node->val;
                }
                poppedNodeList.push_back(node);
            }
            if(levelMaxValue != INT64_MIN){
                ansVector.push_back(levelMaxValue); 
            }
            for(auto node : poppedNodeList){
                if(node != nullptr && node->left != nullptr){
                    nodeStack.push(node->left);
                }
                if(node != nullptr && node->right != nullptr){
                    nodeStack.push(node->right);
                }
            }
        }

        return ansVector;
    }
};
/*
Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]

Constraints:

The number of nodes in the tree will be in the range [0, 10^4].
-231 <= Node.val <= 231 - 1
*/
int main()
{
    TreeNode* leafNode1 = new TreeNode(5);
    TreeNode* leafNode2 = new TreeNode(3);
    TreeNode* leafNode3 = new TreeNode(9);
    TreeNode* node4 = new TreeNode(3, leafNode1, leafNode2);
    TreeNode* node5 = new TreeNode(2, nullptr, leafNode3);
    TreeNode* treeRoot = new TreeNode(1, node4, node5);

    Solution s;
    std::vector<int> ansVector = s.largestValues(treeRoot);
    for (auto element : ansVector)
    {
        std::cout<< element << std::endl;
    }

    return 0;
}