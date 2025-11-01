import sys

def kinkedList():
    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    def KGroup(head: ListNode, k: int) -> ListNode:
        curr = head
        count = 0
        while curr and count < k:
            curr = curr.next
            count += 1
        
        if count < k:
            return head

        prev = None
        current = head
        
        for _ in range(k):
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
            
        head.next = KGroup(current, k)
        
        return prev

    try:
        line1 = sys.stdin.readline().strip().split()
        if not line1: return
        
        k = int(line1[1])
        
        elements_ = sys.stdin.readline().strip().split()
        elements = list(map(int, elements_))
        
    except Exception:
        return

    dummy = ListNode(0)
    current_node = dummy
    for val in elements:
        current_node.next = ListNode(val)
        current_node = current_node.next
    
    head = dummy.next
    
    new_head = KGroup(head, k)
    
    output = []
    current = new_head
    while current:
        output.append(str(current.val))
        current = current.next
        
    print(" ".join(output))

kinkedList()
