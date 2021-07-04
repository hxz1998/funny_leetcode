/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No02dot05 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // 虚拟头节点, 用来标记实际的返回节点头
        ListNode dummy = new ListNode(0);
        // 用来帮助累加的游标节点
        ListNode curr = dummy;
        // 进位
        int carry = 0;
        // 只要有其中一个没有到链表尾,就循环下去
        while (l1 != null || l2 != null) {
            // 如果其中一个已经到尾部,那么就让需要累加的值为 0,否则就是原来的值
            int val1 = l1 == null ? 0 : l1.val;
            int val2 = l2 == null ? 0 : l2.val;
            // 相加
            int sum = val1 + val2 + carry;
            // 创建新节点
            curr.next = new ListNode(sum % 10);
            // 移动游标
            curr = curr.next;
            // 获取进位值
            carry = sum / 10;
            // 移动原链表指针到下一个
            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
        }
        // 检查进位值是否是0,如果不是,那么就创建新节点来存放它
        if (carry != 0) curr.next = new ListNode(carry);
        return dummy.next;
    }
}
