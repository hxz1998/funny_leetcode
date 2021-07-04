/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No02dot01 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode removeDuplicateNodes(ListNode head) {
        ListNode left = head, right = head;
        while (left != null) {
            right = left;
            while (right.next != null) {
                if (right.next.val == left.val) {
                    right.next = right.next.next;
                } else {
                    right = right.next;
                }
            }
            left = left.next;
        }
        return head;
    }
}
