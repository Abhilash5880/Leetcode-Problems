/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root){
    // Base case...
    if(root == NULL){
        return root;
    }
    // Call the function recursively for the left subtree...
    invertTree(root->left);
    // Call the function recursively for the right subtree...
    invertTree(root->right);
    // swapping process...
    struct TreeNode* curr = root->left;
    root->left = root->right;
    root->right = curr;
    return root;        // Return the root...
}