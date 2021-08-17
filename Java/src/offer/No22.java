/*
 * Copyright (c) 8/17/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package offer;

public class No22 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode left = head, right = head.next;
        while (--k > 0) right = right.next;
        while (right != null) {
            right = right.next;
            left = left.next;
        }
        return left;
    }
}
