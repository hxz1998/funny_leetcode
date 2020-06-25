# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# class Solution:
#
#     def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
#         if not l1 and not l2:
#             return None
#         if not l1 and l2:
#             return l2
#         elif not l2 and l1:
#             return l1
#         result = None
#         if l1.val > l2.val:
#             result = ListNode(l2.val)
#             l2 = l2.next
#         else:
#             result = ListNode(l1.val)
#             l1 = l1.next
#         current = result
#         while True:
#             if not l1:
#                 current.next = l2
#                 return result
#             elif not l2:
#                 current.next = l1
#                 return result
#             elif l1.val < l2.val:
#                 tmp = ListNode(l1.val)
#                 current.next = tmp
#                 current = current.next
#                 l1 = l1.next
#             else:
#                 tmp = ListNode(l2.val)
#                 current.next = tmp
#                 current = current.next
#                 l2 = l2.next
#             if not l1 and not l2:
#                 return result

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2

l11 = ListNode(1)
l12 = ListNode(2)
l11.next = l12
l3 = ListNode(4)
l12.next = l3

l6 = ListNode(1)
l4 = ListNode(3)
l6.next = l4
l5 = ListNode(4)
l4.next = l5

s = Solution()
res = s.mergeTwoLists(l11, l6)
while res:
    print(res.val, end='-')
    res = res.next
