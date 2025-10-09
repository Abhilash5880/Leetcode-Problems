#include <stdio.h>
#include <stdlib.h>
/*
// Function to find two numbers that sum to the target
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2; // We are looking for exactly two indices

    // Allocate memory for the result array (to store the two indices)
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        // Handle memory allocation error
        *returnSize = 0;
        return NULL;
    }

    // Iterate through the array with the first pointer 'i'
    for (int i = 0; i < numsSize - 1; i++) {
        // Iterate through the remaining elements with the second pointer 'j'
        for (int j = i + 1; j < numsSize; j++) {
            // Check if the sum of elements at indices 'i' and 'j' equals the target
            if (nums[i] + nums[j] == target) {
                result[0] = i; // Store the index of the first number
                result[1] = j; // Store the index of the second number
                return result; // Return the result array
            }
        }
    }

    // If no solution is found (though the problem usually guarantees one)
    *returnSize = 0;
    free(result); // Free allocated memory
    return NULL;
}
*/


//
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item, *tmpItem;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;
            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }
            return result;
        }
        item = malloc(sizeof(struct hashTable));
        item->key = target - nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }
    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }
    *returnSize = 0;
    // If no valid pair is found, return an empty array
    return malloc(sizeof(int) * 0);
} 
