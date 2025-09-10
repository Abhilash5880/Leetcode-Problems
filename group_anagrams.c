#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Comparison function for qsort to sort characters
int compare_chars(const void* a, const void* b) 
{
    return *(const char*)a - *(const char*)b;
}

// Struct for the hash table
struct AnagramGroup {
    char key[101]; // The sorted string as the key
    //101 is an arbritary buffer to hold the key and null terminator
    char **strings; // This is a dynamic array of character pointers (a jagged array). It holds the original strings that belong to this anagram group.
    int count; //Tracks the current number of strings stored in the strings array.
    int capacity; //Stores the current allocated size of the strings array, used for dynamic resizing.
    UT_hash_handle hh;
};

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    struct AnagramGroup *hashTable = NULL, *item;//initializes the has table
    
    // First pass: build the hash table by sorting strings and grouping
    for (int i = 0; i < strsSize; i++) {
        char* originalStr = strs[i];
        char sortedKey[101];
        strcpy(sortedKey, originalStr); //copies the original string into sortedKey
        qsort(sortedKey, strlen(sortedKey), sizeof(char), compare_chars); //sorts the string

        // Try to find the sorted key in the hash table
        HASH_FIND_STR(hashTable, sortedKey, item);
        /*The macro searches the hash table for a node with a key that matches our sortedKey. If a match is found, item will point to that node; otherwise, item is NULL.*/

        if (item == NULL)
        /*A new anagram group is created. Memory is allocated for the AnagramGroup structure and its strings array. The sorted key is copied, and the new group is added to the hash table with HASH_ADD_STR*/
        {
            // No group exists for this key, create a new one
            item = (struct AnagramGroup*)malloc(sizeof(struct AnagramGroup));
            strcpy(item->key, sortedKey); //the sorted string is stored 
            item->capacity = 1;
            item->count = 0;
            /*The capacity is initialized to 1 (or some starting value), and the count is set to 0. These will be used to track the number of strings in this group.*/
            item->strings = (char**)malloc(item->capacity * sizeof(char*));
            /*A dynamic array of char* (pointers to strings) is allocated. This is where the original strings belonging to this group will be stored. It starts with a capacity of one.*/
            HASH_ADD_STR(hashTable, key, item);
            /* This macro from the uthash library adds the newly created AnagramGroup to the hash table, using the key field for hashing.*/
        }

        // Add the original string to the group
        if (item->count == item->capacity) {
            item->capacity *= 2;
            //The capacity is doubled to make room for more strings. A common dynamic array strategy is to double the capacity to maintain an amortized constant time complexity for additions.
            item->strings = (char**)realloc(item->strings, item->capacity * sizeof(char*));
            //realloc is used to resize the e=memoory block for more strings
        }
        item->strings[item->count] = originalStr;
        //the previous if block will only run of the count matches the capacity....if it is less than capacity...we will juts keep on adding the original strings...
        item->count++;
        //count is incremeneted since new string is added.
    }

    // Second pass: extract the groups from the hash table
    struct AnagramGroup *currGroup, *tmpGroup;
    //currGroup: This pointer will be used to reference the current hash table item (a group of anagrams) during each step of the iteration.
    //tmpGroup: This is a temporary pointer required by HASH_ITER. It's used internally by the macro to safely traverse the hash table's linked list. It is crucial for preventing a crash if you need to delete a hash table item while iterating.
    int groupIndex = 0;//Its purpose is to keep track of the number of anagram groups found and to serve as the index for placing the groups into the final result array.
    
    // Allocate memory for the final result arrays
    char*** result = (char***)malloc(HASH_COUNT(hashTable) * sizeof(char**));
    //*** since it is an array of array of strings...
    /* for only array of string - ** is used
    for only single string - * is used
    for only 1 character - only char is used*/ 
    *returnColumnSizes = (int*)malloc(HASH_COUNT(hashTable) * sizeof(int));
    //This allocates a separate array to store the number of strings in each group. The returnColumnSizes parameter is a pointer to a pointer, so we must dereference it (*returnColumnSizes) to allocate the memory.
    
    HASH_ITER(hh, hashTable, currGroup, tmpGroup) {
        result[groupIndex] = currGroup->strings;
        /* It assigns the pointer to the array of strings (currGroup->strings) from the hash table node to the result array at the current groupIndex. This means the result array is now pointing to the same memory location as the hash table node's string array.*/
        (*returnColumnSizes)[groupIndex] = currGroup->count;
        //size of currGroup->count is stored in this integer array
        groupIndex++;
        
        // Free the hash table items but not the strings arrays
        HASH_DEL(hashTable, currGroup);
        free(currGroup);
        //This line frees the memory that was allocated for the AnagramGroup structure itself. It's important to note that this does not free the currGroup->strings array. That memory block is now owned by the result array and will be freed by the calling function.
    }
    
    *returnSize = groupIndex;
    return result;
    
}