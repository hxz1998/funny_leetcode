/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.List;

public class No17dot12 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    private TreeNode head = new TreeNode(-1);
    private TreeNode prev = null;

    public TreeNode convertBiNode(TreeNode root) {
        dfs(root);
        return head.right;
    }

    private void dfs(TreeNode root) {
        if (root == null) return;
        dfs(root.left);
        if (prev == null) {
            prev = root;
            head.right = root;
        } else {
            prev.right = root;
            prev = root;
        }
        root.left = null;
        dfs(root.right);
    }
}
