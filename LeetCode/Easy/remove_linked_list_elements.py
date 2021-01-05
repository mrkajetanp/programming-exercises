#!/usr/bin/env python3

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(next=head)
        prev = dummy
        curr = head

        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = curr

            curr = curr.next

        return dummy.next
