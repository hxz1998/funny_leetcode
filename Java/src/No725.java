/*
 * Copyright (c) 9/22/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No725 {
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

    public ListNode[] splitListToParts(ListNode head, int k) {
        int size = 0;
        ListNode curr = head;
        while (curr != null) {
            size++;
            curr = curr.next;
        }
        ListNode[] ans = new ListNode[k];
        if (size == 0) return ans;
        curr = head;
        ListNode prev = null;
        int every = size / k, remain = size % k;
        for (int i = 0; i < k; ++i) {
            ans[i] = curr;
            int tEvery = every, tRemain = remain;
            while (tEvery-- > 0) {
                prev = curr;
                curr = curr.next;
            }
            if (tRemain > i) {
                prev = curr;
                curr = curr.next;
            }
            prev.next = null;
        }
        return ans;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1), l2 = new ListNode(2), l3 = new ListNode(3);
        l1.next = l2;
        l2.next = l3;
        No725 no725 = new No725();
        System.out.println(Arrays.toString(no725.splitListToParts(l1, 5)));
    }
}
