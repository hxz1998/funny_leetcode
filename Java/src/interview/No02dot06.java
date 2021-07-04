/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Stack;

public class No02dot06 {
    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
    public boolean isPalindrome(ListNode head) {
        ListNode reverseHead = reverse(head);
        while (head != null) {
            if (head.val != reverseHead.val) return false;
            head = head.next;
            reverseHead = reverseHead.next;
        }
        return true;
    }

    private ListNode reverse(ListNode tail) {
        ListNode head = null;
        while (tail != null) {
            ListNode node = new ListNode(tail.val);
            node.next = head;
            head = node;
            tail = tail.next;
        }
        return head;
    }
    /*public boolean isPalindrome(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        ListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            stack.push(slow.val);
            slow = slow.next;
            fast = fast.next.next;
        }
        if (fast != null) slow = slow.next;
        while (slow != null) {
            if (stack.pop() != slow.val) return false;
            slow = slow.next;
        }
        return true;
    }*/
}
