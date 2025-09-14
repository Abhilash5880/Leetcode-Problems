/**
 * Definition for singly-linked list.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode 
{
     int val;
     struct ListNode *next;
};

struct ListCycle 
{
    struct ListNode* key; // The sorted string as the key
    int index;
    UT_hash_handle hh;
};
//draft 1
bool hasCycle(struct ListNode *head) 

{
    /**
    struct ListCycle *hashTable = NULL;
    struct ListNode* current = head;

    while (current != NULL) {
        struct ListCycle *found_item = NULL;
        // Use HASH_FIND_PTR for pointer keys
        HASH_FIND_PTR(hashTable, &current, found_item); 

        if (found_item != NULL) {
            // Found a node we've already visited
            return true;
        }

        // Add the current node to the hash table
        struct ListCycle* new_item = (struct ListCycle*)malloc(sizeof(struct ListCycle));
        new_item->key = current;
        // Use HASH_ADD_PTR for pointer keys
        HASH_ADD_PTR(hashTable, key, new_item);

        // Move to the next node
        current = current->next;
    }

    // No cycle found
    return false;
**/

//draft 2

    struct ListNode* p=head;
    while(p!==NULL)
    {
        if(p->val==NULL)
        {
            return true;
        }
        else
        {
            p->val=NULL;
            p=p->next;
        }
    }
    return false;
}   