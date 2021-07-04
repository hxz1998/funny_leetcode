/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No02dot02 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public int kthToLast(ListNode head, int k) {
        // left 用来定位倒数第 k 个节点,right 用来定位最后一个节点
        ListNode left = head, right = head;
        // 首先让 right 和 left 之间错开 k - 1 个位置
        while (--k > 0) right = right.next;
        // 然后一起往链表末尾移动,直到 right 抵达最后一个节点
        while (right != null) {
            right = right.next;
            left = left.next;
        }
        // 返回 left 指向的节点数据
        return left.val;
    }
}
