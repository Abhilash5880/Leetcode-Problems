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
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// We must pass 'i' as a pointer (int*) so the index is shared and updated across all recursive calls.
// The array 'arr' is passed as a pointer (int*) since arrays decay to pointers in C.
void Inorder(struct TreeNode* root, int* arr, int* i)
{
    if(root==NULL)
    {
        return;
    }

    Inorder(root->left,arr,i);
    
    // Use the dereferenced pointer (*i) to access and update the shared index variable.
    arr[*i]=root->val;
    (*i)++;

    Inorder(root->right,arr,i);

    // No return needed since we modify the array and index directly.

}

int kthSmallest(struct TreeNode* root, int k) 
{
    int arr[10000];
    int i=0;

    // Pass the root, the array pointer (arr), and the address of the index (&i).
    Inorder(root,arr,&i);
    return arr[k-1];
}