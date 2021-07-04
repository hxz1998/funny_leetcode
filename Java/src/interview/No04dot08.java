/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No04dot08 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (!cover(root, p) || !cover(root, q)) return null;
        return helper(root, p, q);
    }

    private TreeNode helper(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) return root;
        boolean pisOnLeft = cover(root.left, p);
        boolean qisOnLeft = cover(root.left, q);
        if (pisOnLeft != qisOnLeft) return root;
        if (pisOnLeft) return helper(root.left, p, q);
        else return helper(root.right, p, q);
    }

    private boolean cover(TreeNode root, TreeNode node) {
        if (root == null) return false;
        if (root == node) return true;
        return cover(root.left, node) || cover(root.right, node);
    }
}
