# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class ListNode:
    def __init__(self, x):
        self.value = x
        self.next = None


class Solution:
    cur = 0

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head: return head
        head.next = self.removeNthFromEnd(head.next, n)
        self.cur += 1
        if self.cur == n: return head.next
        return head


s = Solution()
l1 = ListNode(1)
l2 = ListNode(2)
l1.next = l2
l3 = ListNode(3)
l2.next = l3
l4 = ListNode(4)
l3.next = l4
l5 = ListNode(5)
l4.next = l5

l = s.removeNthFromEnd(l1, 2)
while l:
    print(l.value)
    l = l.next
