/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;

public class No04dot03 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public ListNode[] listOfDepth(TreeNode tree) {
        // 用来构建返回值的
        ArrayList<ListNode> ans = new ArrayList<>();
        // 帮助用来层序遍历的队列
        Queue<TreeNode> queue = new ArrayDeque<>();
        // 先把树的根节点入队
        queue.offer(tree);
        while (!queue.isEmpty()) {
            // 逐层遍历树
            int size = queue.size();
            // dummy 节点是用来标记链表头节点的辅助节点
            ListNode dummy = new ListNode(0);
            // curr 节点用来逐个连接新节点
            ListNode curr = dummy;
            for (int i = 0; i < size; ++i) {
                // 遍历这一层的所有节点
                TreeNode treeNode = queue.poll();
                // 连接链表
                curr.next = new ListNode(treeNode.val);
                curr = curr.next;
                // 把这一层所有节点的左右子节点放到队列中去
                if (treeNode.left != null) queue.offer(treeNode.left);
                if (treeNode.right != null) queue.offer(treeNode.right);
            }
            // 把这一层的链表头放到返回值中
            ans.add(dummy.next);
        }
        return ans.toArray(new ListNode[0]);
    }
}
