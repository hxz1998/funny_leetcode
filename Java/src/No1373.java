/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1373 {
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

    private int ans = 0;

    public int maxSumBST(TreeNode root) {
        findMaxSumBST(root);
        return ans;
    }

    private void findMaxSumBST(TreeNode root) {
        if (isBST(root, Integer.MAX_VALUE, Integer.MIN_VALUE)) {
            sum(root);
            return;
        }
        findMaxSumBST(root.left);
        findMaxSumBST(root.right);
    }

    private boolean isBST(TreeNode root, int max, int min) {
        if (root == null) return true;
        return (root.val > min && root.val < max && isBST(root.left, root.val, min) && isBST(root.right, max, root.val));
    }

    private int sum(TreeNode root) {
        if (root == null) return 0;
        int cur = root.val + sum(root.left) + sum(root.right);
        ans = Math.max(ans, cur);
        return cur;
    }
}
