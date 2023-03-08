#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
/* Function to find the candidate for Majority */

class Solution {
public:
    struct node
    {
        int key;
        int c = 0;
        struct node *left, *right;
    };
    
    struct node *newNode(int item)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->key = item;
        temp->c = 1;
        temp->left = temp->right = NULL;
        return temp;
    }

    // A utility function to insert a new node with given key in
    // BST
    struct node *insert(struct node *node, int key, int &ma)
    {
        // If the tree is empty, return a new node
        if (node == NULL)
        {
            if (ma == 0)
                ma = 1;

            return newNode(key);
        }

        // Otherwise, recur down the tree
        if (key < node->key)
            node->left = insert(node->left, key, ma);
        else if (key > node->key)
            node->right = insert(node->right, key, ma);
        else
            node->c++;

        // find the max count
        ma = max(ma, node->c);

        // return the (unchanged) node pointer
        return node;
    }

    // A utility function to do inorder traversal of BST
    int inorder(struct node *root, int s, int &v)
    {
        if (root != NULL)
        {
            inorder(root->left, s, v);

            if (root->c > (s / 2))
                v = root->key;

            inorder(root->right, s, v);
        }

        return v;
    }
    
    int majorityElement(vector<int>& nums) {
        struct node *root = NULL;
        int ma = 0;

        for (int i = 0; i < nums.size(); i++)
            root = insert(root, nums[i], ma);
        int v = -1;
        return inorder(root,nums.size(),v);
    }
    
};
// Driver Code
int main()
{
    

    return 0;
}