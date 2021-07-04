/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import com.sun.source.tree.Tree;

import java.util.LinkedList;
import java.util.Queue;

public class No623 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            // 先把特例处理掉，如果需要在根节点处添加，
            // 那么就直接新建一个根节点，然后根节点的左指针指向原来的根节点就好了
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }
        // 使用队列，来逐层遍历
        Queue<TreeNode> queue = new LinkedList<>();
        // 首先把根节点放进来
        queue.offer(root);
        // 定位到目标深度的前一行
        while (--depth > 1) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode node = queue.poll();
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
        }
        int size = queue.size();
        // 添加一行新的节点
        for (int i = 0; i < size; ++i) {
            TreeNode node = queue.poll();
            // 先记录下来左右子节点
            TreeNode left = node.left;
            TreeNode right = node.right;
            // 新建左右子节点
            node.left = new TreeNode(val);
            node.right = new TreeNode(val);
            // 左节点的左节点是之前的左节点
            node.left.left = left;
            // 右节点的右节点是之前的右节点
            node.right.right = right;
        }
        return root;
    }

    public static void main(String[] args) {
        TreeNode node1 = new TreeNode(4), node2 = new TreeNode(2),
                node3 = new TreeNode(6), node4 = new TreeNode(3),
                node5 = new TreeNode(1), node6 = new TreeNode(5);
        node1.left = node2;
        node1.right = node3;
        node2.left = node4;
        node2.right = node5;
        node3.left = node6;
        No623 no623 = new No623();
        System.out.println(no623.addOneRow(node1, 1, 3));
    }
}
