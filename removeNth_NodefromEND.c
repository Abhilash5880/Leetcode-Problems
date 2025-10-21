/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*    //greedy approach
    struct ListNode* front=head;
    struct ListNode* back=head;

    for (int i = 0; i < n; i++) {
        if (front == NULL) {
            // establishing the 'n' nodes gap
            return head; 
        }
        front = front->next;
    }
    
    while(front->next!=NULL)
    {
        front=front->next;
        back=back->next;
    }
    struct ListNode* temp=back->next;
    free(temp);
    back->next=back->next->next;
    return head;
*/
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // 1. Create a dummy node. This is a crucial step to handle the edge case 
    //    where the node to be removed is the head itself (e.g., n = list length).
    struct ListNode dummy;
    dummy.next = head;

    // Initialize two pointers, both starting at the dummy node.
    // 'slow' will stop just before the node we need to remove.
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // 2. Move the 'fast' pointer N steps ahead. This establishes the N-gap.
    //    The distance between fast and slow will be exactly N.
    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            // Should not happen based on typical constraints, but a safeguard.
            return head; 
        }
        fast = fast->next;
    }

    // 3. Move both pointers simultaneously until 'fast' hits the last node.
    //    Since fast is N nodes ahead, when fast reaches the end, slow will be 
    //    at the N+1 position from the end (i.e., the node BEFORE the target).
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // 4. Perform the removal. 'slow' is pointing to the node just before the target.
    struct ListNode* target_node = slow->next;

    // Bypass the target node.
    slow->next = slow->next->next;

    // Note: In a real C environment, you would call free(target_node) here 
    // to prevent a memory leak.

    // 5. Return the new head of the list, which is dummy.next.
    return dummy.next;
}