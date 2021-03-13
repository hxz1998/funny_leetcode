import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class No1019 {
    public int[] nextLargerNodes(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        List<Integer> list = new ArrayList<>();
        ListNode node = head;
        while (node != null) {
            list.add(node.val);
            node = node.next;
        }
        int[] ans = new int[list.size()];
        for (int i = 0; i < list.size(); ++i) {
            while (!stack.empty() && list.get(stack.peek()) < list.get(i)) {
                ans[stack.pop()] = list.get(i);
            }
            stack.push(i);
        }
        return ans;
    }

    public static void main(String[] args) {
        ListNode node1 = new ListNode(2), node2 = new ListNode(7),
                node3 = new ListNode(4), node4 = new ListNode(3), node5 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        No1019 no1019 = new No1019();
        System.out.println(no1019.nextLargerNodes(node1));

    }
}
