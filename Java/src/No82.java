/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No82 {
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
        // 首先检查特殊情况，排除掉
        if (head == null) return null;
        // 设置用来时刻跟进修改进度的指针，
        // 该指针上一次和下一次指向的节点一定中间没有重复值
        ListNode modifyNode = new ListNode(0);
        // 用来帮助找到返回值的哨兵指针，虚拟头节点
        ListNode guard = modifyNode;
        guard.next = head;
        // 用来逐个遍历链表中元素的指针
        ListNode current = head;
        // 逐个检查，前提是当前元素不为空而且下个元素也不为空
        while (current != null && current.next != null) {
            // 如果当前元素和下一个元素值重复了，那么就开始 【跳】，直接让 current 跳到不重复的元素那里
            if (current.val == current.next.val) {
                int val = current.val;
                while (current != null && current.val == val) current = current.next;
                // 然后让跟进修改进度的指针下一个位置指向 current，中间略过重复元素
                modifyNode.next = current;
            } else {
                // 如果不重复，那么这俩指针一起往后走
                current = current.next;
                modifyNode = modifyNode.next;
            }
        }
        // 返回哨兵指针指向的头节点
        return guard.next;
    }
}
