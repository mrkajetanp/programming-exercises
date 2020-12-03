#!/usr/bin/env python3

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
    dummy_head = ListNode()

    curr = dummy_head
    while l1 or l2:
        if l2 is None or (l1 is not None and l1.val < l2.val):
            curr.next = l1
            l1 = l1.next
        else:
            curr.next = l2
            l2 = l2.next
        curr = curr.next

    return dummy_head.next
