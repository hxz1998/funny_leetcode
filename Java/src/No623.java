/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

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
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (--depth > 1) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode node = queue.poll();
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
        }
        for (int i = 0; i < queue.size(); ++i) {
            TreeNode node = queue.poll();
            TreeNode left = node.left;
            TreeNode right = node.right;
            node.left = new TreeNode(val);
            node.right = new TreeNode(val);
            node.left.left = left;
            node.right.right = right;
        }
        return root;
    }

    public static void main(String[] args) {
        TreeNode node1 = new TreeNode(4), node2 =
    }
}
