/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<stdio.h>
#include<stdbool.h>

struct TreeNode 
{
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

// A helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxDepth(struct TreeNode* root) {
    // Base case: If the node is NULL, its depth is 0.
    if (root == NULL) {
        return 0;
    }
    
    // Recursively calculate the depth of the left and right subtrees.
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    
    // The depth of the current tree is 1 (for the root itself) 
    // plus the maximum depth of its left or right subtree.
    return 1 + max(left_depth, right_depth);

}