/*
 * Copyright (c) 8/17/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No979 {
    private static class TreeNode {
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

    private int ans = 0;

    public int distributeCoins(TreeNode root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) return 0;
        // 计算左边的过载量
        int left = dfs(root.left);
        // 计算右边的过载量
        int right = dfs(root.right);
        // 累加起来左右两边的过载量，代表需要移动的个数
        ans += Math.abs(left) + Math.abs(right);
        // 返回当前节点的过载量
        return left + right + root.val - 1;
    }
}
