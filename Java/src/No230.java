/*
 * Copyright (c) 10/17/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No230 {
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

    private int curr = 0;
    private int ans = -1;

    public int kthSmallest(TreeNode root, int k) {
        inorderTraversal(root, k);
        return ans;
    }

    private void inorderTraversal(TreeNode root, int k) {
        if (root == null) return;
        inorderTraversal(root.left, k);
        curr++;
        if (curr == k && ans == -1) {
            ans = root.val;
            return;
        }
        inorderTraversal(root.right, k);
    }

    public static void main(String[] args) {
        TreeNode node5 = new TreeNode(5), node3 = new TreeNode(3), node6 = new TreeNode(6), node2 = new TreeNode(2),
                node4 = new TreeNode(4), node1 = new TreeNode(1);
        node5.left = node3;
        node5.right = node6;
        node3.left = node2;
        node3.right = node4;
        node2.left = node1;
        No230 no230 = new No230();
        System.out.println(no230.kthSmallest(node5, 3));
    }
}
