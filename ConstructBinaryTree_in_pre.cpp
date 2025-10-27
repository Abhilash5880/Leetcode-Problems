/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to recursively build the tree
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        map<int, int> &inmap) {
        // Step 6: Base case - invalid range
        if (inStart > inEnd || preStart > preEnd)
            return NULL;
        
        // Step 2: First element in preorder is the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Step 3: Find root position in inorder using hashmap
        int inRoot = inmap[root->val];
        
        // Step 4: Calculate number of nodes in left subtree
        int numsleft = inRoot - inStart;

        // Step 5: Recursively build left and right subtrees
        // Left subtree: next numsleft elements in preorder
        root->left = buildTree(preorder, preStart + 1, preStart + numsleft,
                               inorder, inStart, inRoot - 1, inmap);
        
        // Right subtree: remaining elements in preorder
        root->right = buildTree(preorder, preStart + 1 + numsleft, preEnd,
                                inorder, inRoot + 1, inEnd, inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Step 1: Build hashmap for O(1) inorder index lookup
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        
        // Start recursive tree construction
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, 
                                   inorder, 0, inorder.size() - 1, inmap);
        return root;
    }
};