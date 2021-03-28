/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No83 {
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

    public ListNode deleteDuplicates(ListNode head) {
        // 使用 modify 指针去不断修改 next 指向的下一个元素，从而跳过重复元素，只保留一个
        ListNode modify = head;
        // 循环条件确保循环体内的元素有效不为 null
        while (modify != null && modify.next != null) {
            // 如果 modify 的数值等于 modify 下一个元素的数值，那么直接让 modify 指向下一个元素的下一个
            if (modify.val == modify.next.val) modify.next = modify.next.next;
            // 否则的话就让 modify 元素下移一个位置
            else modify = modify.next;
        }
        return head;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1), l2 = new ListNode(2), l3 = new ListNode(3);
        l1.next = l2;
        l2.next = l3;
        No83 no83 = new No83();
        no83.deleteDuplicates(l1);
    }
}
