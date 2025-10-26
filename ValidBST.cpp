/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef long long Boundary;

bool isValidBST_Helper(struct TreeNode* root, Boundary min_bound, Boundary max_bound) {
    // Base case: An empty tree is a valid BST.
    if (root == NULL) {
        return true;
    }

    // 1. Check current node against its current bounds (The Global Check).
    // The value must be strictly greater than the lower bound (min_bound)
    // AND strictly less than the upper bound (max_bound).
    if (root->val <= min_bound || root->val >= max_bound) {
        return false;
    }

    // 2. Recursive Check for Left Subtree:
    // When moving left, the new maximum bound becomes the current node's value.
    // (Everything in the left must be < root->val). The minimum bound remains the same.
    if (!isValidBST_Helper(root->left, min_bound, (Boundary)root->val)) {
        return false;
    }

    // 3. Recursive Check for Right Subtree:
    // When moving right, the new minimum bound becomes the current node's value.
    // (Everything in the right must be > root->val). The maximum bound remains the same.
    if (!isValidBST_Helper(root->right, (Boundary)root->val, max_bound)) {
        return false;
    }

    // If all checks pass for the current node and its subtrees, it is valid.
    return true;
}

/**
 * Main function to initiate the BST validation.
 */
bool isValidBST(struct TreeNode* root) {
    // Start the recursion with the widest possible range: (-infinity, +infinity)
    return isValidBST_Helper(root, LLONG_MIN, LLONG_MAX);
}