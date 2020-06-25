# Definition for singly-linked list.
from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        stack = []
        for node in lists:
            while node:
                stack.append(node.val)
                node = node.next
        result = tem =
        pass

