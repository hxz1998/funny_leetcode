/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No61 {
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

    public ListNode rotateRight(ListNode head, int k) {
        // 首先把链表为空的特殊情况处理掉
        if (head == null) return null;
        // 然后设置快慢指针
        ListNode fast = head, slow = head;
        int size = 0;
        while (fast != null) {
            size++;
            fast = fast.next;
        }
        k %= size;
        fast = head;
        // 用快指针去找到倒数第 k+1 个元素
        for (int i = 0; i < k; ++i) {
            if (fast.next == null) fast = head;
            else fast = fast.next;
        }
        // 用慢指针去定位到新链表的尾部
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        // 将原来的链表连成环
        fast.next = head;
        // 找到新链表的头节点
        head = slow.next;
        // 再把环切断
        slow.next = null;
        return head;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1), l2 = new ListNode(2), l3 = new ListNode(3), l4 = new ListNode(4), l5 = new ListNode(5);
        l1.next = l2;
        l2.next = l3;
        l3.next = l4;
        l4.next = l5;
        No61 no61 = new No61();
        no61.rotateRight(l1, 2);
    }
}
