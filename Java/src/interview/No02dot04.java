/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No02dot04 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode partition(ListNode head, int x) {
        ListNode leftHead = new ListNode(0);
        ListNode leftCurrent = leftHead;
        ListNode rightHead = new ListNode(0);
        ListNode rightCurrent = rightHead;
        while (head != null) {
            if (head.val < x) {
                leftCurrent.next = new ListNode(head.val);
                leftCurrent = leftCurrent.next;
            } else {
                rightCurrent.next = new ListNode(head.val);
                rightCurrent = rightCurrent.next;
            }
            head = head.next;
        }
        leftCurrent.next = rightHead;
        return leftHead.next;
    }
}
