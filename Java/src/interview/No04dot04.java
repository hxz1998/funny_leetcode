/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No04dot04 {
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    private int dfs(TreeNode root) {
        if (root == null) return -1;
        int leftHeight = dfs(root.left);
        if (leftHeight == Integer.MAX_VALUE) return Integer.MAX_VALUE;
        int rightHeight = dfs(root.right);
        if (rightHeight == Integer.MAX_VALUE) return Integer.MAX_VALUE;
        int diff = Math.abs(leftHeight - rightHeight);
        if (diff > 1) return Integer.MAX_VALUE;
        else return Math.max(leftHeight, rightHeight) + 1;
    }

    public boolean isBalanced(TreeNode root) {
        return dfs(root) != Integer.MAX_VALUE;
    }
}
