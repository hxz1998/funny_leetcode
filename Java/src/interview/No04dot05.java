/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No04dot05 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    private Integer lastVisited = null;

    private boolean check(TreeNode root) {
        if (root == null) return true;

        if (!check(root.left)) return false;
        if (lastVisited != null && lastVisited >= root.val) return false;

        lastVisited = root.val;

        if (!check(root.right)) return false;
        return true;
    }

    public boolean isValidBST(TreeNode root) {
        return check(root);
    }
}
