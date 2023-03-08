#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using std::queue;
using std::vector;
/*
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. 
Answers within 10-5 of the actual answer will be accepted.
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
    // Solution 1
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        vector<int> levelVals;
        int level = 0, levelCount = 1, nextLevelCount = 0;
        
        q.push(root);
        
        while(q.size()!=0){
            TreeNode* cur = q.front();
            q.pop();
            
            levelVals.push_back(cur->val);
            
            levelCount--;
            
            if(cur->left!=NULL){
                q.push(cur->left);
                nextLevelCount++;
            }
            
            if(cur->right!=NULL){
                q.push(cur->right);
                nextLevelCount++;
            }
            
            if(levelCount==0){
                levelCount = nextLevelCount;
                nextLevelCount = 0;
                level++;
                double levelSum = accumulate(levelVals.begin(), levelVals.end(), 0.0);
                ans.push_back(levelSum/levelVals.size());
                levelVals.clear();
            }
        }
        
        return ans;
    }

    // Solution 2
    // void fillVectors(TreeNode* cur, int level, vector<double>& sum, vector<int>& count){
    //     if(cur==NULL) return;
        
    //     if(level < sum.size()){
    //         sum[level]+=cur->val;
    //         count[level]+=1;
    //         // std::cout << cur->val << std::endl;
    //     }else{
    //         sum.push_back(cur->val);
    //         count.push_back(1);
    //         // std::cout << cur->val << std::endl;
    //     }
        
    //     //DFS
    //     fillVectors(cur->left, level+1, sum, count);
    //     fillVectors(cur->right, level+1, sum, count);
    // }
    // vector<double> averageOfLevels(TreeNode* root) {
    //     vector<double> ans;
    //     vector<double> sum;
    //     vector<int> count;
        
    //     fillVectors(root, 0, sum, count);
        
    //     for(int i = 0; i < sum.size(); i++){
    //         ans.push_back(sum[i]/count[i]);
    //     }
    //     return ans;
    // }
};
/*
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
Example 2:

Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
*/
int main(){
    Solution s;
    TreeNode t4(15),t5(7);
    TreeNode t2(9),t3(20,&t4,&t5);
    TreeNode t1(3,&t2,&t3);
    vector<double> vec = s.averageOfLevels(&t1);
    for(int i=0;i<vec.size();i++){
        std::cout<< vec[i] << std::endl;
    }
    return 0;
}