/*
 * Copyright (c) 8/5/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No889 {
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

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int n = preorder.length;
        if (n == 0) return null;
        TreeNode root = new TreeNode(preorder[0]);
        if (n == 1) return root;
        int idx = -1;
        for (int i = 0; i < n; ++i) if (postorder[i] == preorder[1]) idx = i + 1;
        root.left = constructFromPrePost(
                Arrays.copyOfRange(preorder, 1, idx + 1),
                Arrays.copyOfRange(postorder, 0, idx));
        root.right = constructFromPrePost(
                Arrays.copyOfRange(preorder, idx + 1, n),
                Arrays.copyOfRange(postorder, idx, n - 1));
        return root;
    }

    public static void main(String[] args) {
        int[] preorder = {1, 2, 4, 5, 3, 6, 7};
        int[] postorder = {4, 5, 2, 6, 7, 3, 1};
        No889 no889 = new No889();
        no889.constructFromPrePost(preorder, postorder);
    }
}
