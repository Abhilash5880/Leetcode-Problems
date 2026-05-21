class Solution {
public:

    Node* copyRandomList(Node* head) {

        if(head == NULL)
        {
            return NULL;
        }

        unordered_map<Node*, Node*> mp;

        Node* temp = head;

        // PASS 1
        // Create all copied nodes

        while(temp != NULL)
        {
            Node* copyNode = new Node(temp->val);

            mp[temp] = copyNode;

            temp = temp->next;
        }

        temp = head;

        // PASS 2
        // Connect next and random pointers

        while(temp != NULL)
        {
            mp[temp]->next = mp[temp->next];

            mp[temp]->random = mp[temp->random];

            temp = temp->next;
        }

        return mp[head];
    }
};