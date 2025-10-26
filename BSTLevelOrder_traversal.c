/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#define MAX_QUEUE_SIZE 2000 // Constraint based on typical problem sizes
typedef struct {
    struct TreeNode* items[MAX_QUEUE_SIZE]; /*this is an array or TreeNodes*/
    int front;
    int rear;
} Queue;

// Function to initialize the queue.
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        //memory allocation failure
        return NULL;
    }
    q->front = -1; //initializing both pointers (-1 means queue is empty)
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty.
int isEmpty(Queue* q) {
    return q->rear == -1;
}

// Function to add a node pointer to the rear of the queue.
void enqueue(Queue* q, struct TreeNode* node) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        //queue overflow (shouldn't happen with large enough MAX_QUEUE_SIZE)
        return;
    }
    if (q->front == -1) 
    {
        q->front = 0; /* move front forward to ensure start of queue*/
    }
    q->items[++q->rear] = node; 
}

// Function to remove and return the node pointer from the front of the queue.
struct TreeNode* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    struct TreeNode* node = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1; /*edge case*/
    } else {
        q->front++;
    }
    return node;
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = 0;
    if (root == NULL) 
    {
        
        return NULL;
    }

    Queue* q = createQueue();
    if (q == NULL) return NULL; // Allocation failure check
    enqueue(q, root);

    // Initial capacity for the result (list of levels)
    int result_capacity = 10;
    int** result = (int**)malloc(result_capacity * sizeof(int*));
    int* col_sizes = (int*)malloc(result_capacity * sizeof(int));
    if (result == NULL || col_sizes == NULL) return NULL; // Allocation failure check

    // 3. BFS Main Loop
    while (!isEmpty(q)) {
        int level_size = q->rear - q->front + 1; // Number of nodes at the current level
        
        // Dynamic resizing for the result array if needed
        if (*returnSize == result_capacity) {
            result_capacity *= 2;
            result = (int**)realloc(result, result_capacity * sizeof(int*));
            col_sizes = (int*)realloc(col_sizes, result_capacity * sizeof(int));
        }

        // Initialize the current level's array (row)
        int current_level_capacity = level_size;
        int* current_level = (int*)malloc(current_level_capacity * sizeof(int));
        
        if (current_level == NULL) return NULL; // Allocation failure check

        // 4. Process all nodes in the current level
        for (int i = 0; i < level_size; ++i) {
            struct TreeNode* node = dequeue(q);
            
            // Store the node's value in the current level's array
            current_level[i] = node->val;

            // Enqueue children for the next level
            if (node->left != NULL) {
                enqueue(q, node->left);
            }
            if (node->right != NULL) {
                enqueue(q, node->right);
            }
        }

        // 5. Finalize storage for the current level
        result[*returnSize] = current_level;
        col_sizes[*returnSize] = level_size;
        (*returnSize)++;
    }

    // 6. Clean up the queue structure
    free(q);

    // 7. Set the column sizes pointer and return the 2D array
    *returnColumnSizes = col_sizes;
    return result;
    
}