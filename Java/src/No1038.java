/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */


public class No1038 {
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
    private int curr = 0;

    public TreeNode bstToGst(TreeNode root) {
        add(root);
        modify(root);
        return root;
    }

    private void add(TreeNode root) {
        if (root == null) return;
        add(root.left);
        sum += root.val;
        add(root.right);
    }

    private void modify(TreeNode root) {
        if (root == null) return;
        modify(root.left);
        int value = root.val;
        root.val = sum - curr;
        curr += value;
        modify(root.right);
    }
}
