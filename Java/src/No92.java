/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */


public class No92 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode guard = new ListNode(0, head), current = head, ret = guard;
        for (int i = 0; i < left - 1; ++i) guard = guard.next;
        current = guard.next;
        for (int i = left; i < right; ++i) {
            ListNode remove = current.next;
            current.next = current.next.next;
            remove.next = guard.next;
            guard.next = remove;
        }
        return ret.next;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(3), l2 = new ListNode(5), l3 = new ListNode(3), l4 = new ListNode(4), l5 = new ListNode(5);
        l1.next = l2;
//        l2.next = l3;
//        l3.next = l4;
//        l4.next = l5;
        No92 no92 = new No92();
        no92.reverseBetween(l1, 1, 2);
    }
}
