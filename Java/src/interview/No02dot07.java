/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No02dot07 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    static class Result {
        int size = 0;
        ListNode tail = null;

        Result(int size, ListNode tail) {
            this.size = size;
            this.tail = tail;
        }
    }

    // 更神奇的方法
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode l1 = headA;
        ListNode l2 = headB;
        while (l1 != l2) {
            l1 = l1 == null ? headB : l1.next;
            l2 = l2 == null ? headA : l2.next;
        }
        return l1;
    }

//    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
//        // 首先把空链表的情况排除掉
//        if (headA == null || headB == null) return null;
//        // 对链表大小进行计数,同时定位最后一个链表节点
//        int size1 = 1, size2 = 1;
//        ListNode tail1 = headA, tail2 = headB;
//        while (tail1.next != null) {
//            tail1 = tail1.next;
//            size1++;
//        }
//        while (tail2.next != null) {
//            tail2 = tail2.next;
//            size2++;
//        }
//        // 如果最后一个节点不是同一个,那么说明根本不会相交,所以直接返回空节点
//        if (tail2 != tail1) return null;
//        // 计算两个链表长度差值
//        int diff = Math.abs(size1 - size2);
//        // 如果链表 A 比 B 长,那么先把 A 的指针往后偏移 diff 个, 否则就便宜 B 的指针
//        if (size1 > size2) while (--diff >= 0) headA = headA.next;
//        else if (size1 < size2) while (--diff >= 0) headB = headB.next;
//        // 找到相同的位置,并返回
//        while (headA != headB) {
//            headA = headA.next;
//            headB = headB.next;
//        }
//        return headA;
//    }

    public static void main(String[] args) {
        // [4,1,8,4,5]
        // [5,0,1,8,4,5]
        ListNode l1 = new ListNode(4), l2 = new ListNode(1), l3 = new ListNode(8), l4 = new ListNode(4), l5 = new ListNode(5);
        l1.next = l2;
        l2.next = l3;
        l3.next = l4;
        l4.next = l5;
        ListNode r1 = new ListNode(5), r2 = new ListNode(0);
        r1.next = r2;
        r2.next = l2;
        No02dot07 no02dot07 = new No02dot07();
        no02dot07.getIntersectionNode(l1, r1);

    }
}
