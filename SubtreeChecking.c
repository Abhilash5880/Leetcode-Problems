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

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (subRoot == NULL) {
        return true;
    }
    if (root == NULL) {
        return false;
    }
    
    // Check if the current tree starting at 'root' is identical to 'subRoot'
    if (isSameTree(root, subRoot)) {
        return true;
    }

    // If not, check if 'subRoot' is a subtree of the left OR right child
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}