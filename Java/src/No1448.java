/*
 * Copyright (c) 8/12/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1448 {
    class TreeNode {
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

    public int goodNodes(TreeNode root) {
        ans = 0;
        dfs(root, root.val);
        return ans;
    }

    private void dfs(TreeNode root, int max) {
        if (root == null) return;
        if (root.val > max) {
            max = root.val;
            ans++;
        }
        dfs(root.left, max);
        dfs(root.right, max);
    }
}
