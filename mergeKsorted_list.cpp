class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto l : lists) {
            if (l) pq.push(l);
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = tail->next;
            if (curr->next) pq.push(curr->next);
        }
        return dummy->next;
    }
};