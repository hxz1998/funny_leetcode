/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No04dot12 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    private int count = 0;

    public int pathSum(TreeNode root, int sum) {
        if (root == null) return 0;
        dfs(root, 0, sum);
        pathSum(root.left, sum);
        pathSum(root.right, sum);
        return count;
    }

    private void dfs(TreeNode root, int buffer, int sum) {
        if (root == null) return;
        if (buffer + root.val == sum) count++;
        dfs(root.left, buffer + root.val, sum);
        dfs(root.right, buffer + root.val, sum);
    }
}
