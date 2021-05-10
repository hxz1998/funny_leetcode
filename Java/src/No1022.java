/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1022 {
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

    private int sum = 0;

    public int sumRootToLeaf(TreeNode root) {
        dfs(root, 0);
        return sum;
    }

    private void dfs(TreeNode root, int curr) {
        if (root == null) return;
        curr = (curr << 1) + root.val;
        if (root.left == null && root.right == null) sum += curr;
        dfs(root.left, curr);
        dfs(root.right, curr);
    }

    public static void main(String[] args) {
        TreeNode node1 = new TreeNode(1),
                node2 = new TreeNode(0),
                node3 = new TreeNode(1),
                node4 = new TreeNode(0),
                node5 = new TreeNode(1),
                node6 = new TreeNode(0),
                node7 = new TreeNode(1);
        node1.left = node2;
        node1.right = node3;
        node2.left = node4;
        node2.right = node5;
        node3.left = node6;
        node3.right = node7;
        No1022 no1022 = new No1022();
        System.out.println(no1022.sumRootToLeaf(node1));
    }
}
