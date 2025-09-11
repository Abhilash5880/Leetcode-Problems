/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

struct ListNode* insertAtEnd(struct ListNode* head, int x)
{
	struct ListNode* ptr=(struct ListNode*)malloc(sizeof(struct ListNode));
    if(ptr==NULL)
    {
    	printf("Memory not allocated :\n");
    	return head;
    }
	ptr->val=x;
    ptr->next=NULL;
    if(head==NULL)
    {
    	printf("Success! Head element %d added.\n",x);
        return ptr;
	}
    else
    {
    	struct ListNode* p=head;
    	while(p->next!=NULL)
    	{
    		p=p->next;
    	}
    	p->next=ptr;
    }
	printf("Success! Element %d added.\n ",x);
	return head;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{

    int final_array[100]={0};
    struct ListNode* list_array = list1;
    int i=0;
    while (list_array!=NULL)
    {
        final_array[i]=list_array->val;
        list_array=list_array->next;
        i++;
    }
    list_array=list2;
    while(list_array!=NULL)
    {
        final_array[i]=list_array->val;
        list_array=list_array->next;
        i++;
    }
    
    qsort(final_array, i, sizeof(int), compare_ints);
    
    //decalration of the final linked list
    struct ListNode* final_list=NULL;
    
    //insertion function for the final linked list
    
    for(int j=0; j<i; j++)
    {
        final_list=insertAtEnd(final_list, final_array[j]);
    }

    return final_list;
}