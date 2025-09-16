/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    // Both are NULL, they are the same
    if (p == NULL && q == NULL) {
        return true;
    }
    // One is NULL or their values are different, they are not the same
    if (p == NULL || q == NULL || p->val != q->val) {
        return false;
    }
    // Recursively check the left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}