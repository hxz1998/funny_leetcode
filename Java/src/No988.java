/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No988 {
    private String ans = "~";

    public String smallestFromLeaf(TreeNode root) {
        dfs(root, new StringBuilder());
        return ans;
    }

    private void dfs(TreeNode root, StringBuilder builder) {
        if (root == null) return;
        builder.append((char)('a' + root.val));
        if (root.left == null && root.right == null) {
            builder.reverse();
            String s = builder.toString();
            if (s.compareTo(ans) < 0) ans = s;
            builder.reverse();
        }
        dfs(root.left, builder);
        dfs(root.right, builder);
        builder.deleteCharAt(builder.length() - 1);
    }

    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
}
