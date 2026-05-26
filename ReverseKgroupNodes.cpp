class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {

        // dummy node for easier connections
        ListNode* dummy = new ListNode(0);

        dummy->next = head;

        // tail of previous reversed group
        ListNode* prevGroupTail = dummy;

        while(true)
        {
            // scout pointer
            ListNode* scout = prevGroupTail;

            // check if k nodes exist
            for(int i=0; i<k; i++)
            {
                scout = scout->next;

                if(scout == NULL)
                {
                    return dummy->next;
                }
            }

            // start of current group
            ListNode* left = prevGroupTail->next;

            // node after current k-group
            ListNode* groupNext = scout->next;

            // reversal pointers
            ListNode* prev = groupNext;

            ListNode* curr = left;

            // reverse exactly k nodes
            for(int i=0; i<k; i++)
            {
                ListNode* nextNode = curr->next;

                curr->next = prev;

                prev = curr;

                curr = nextNode;
            }

            // connect previous group to new head
            prevGroupTail->next = prev;

            // update prevGroupTail
            prevGroupTail = left;
        }
    }
};