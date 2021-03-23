/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */


public class No1008 {
    private TreeNode root;

    public TreeNode bstFromPreorder(int[] preorder) {
        // 首先二话不说，把根节点置为第一个元素
        root = new TreeNode(preorder[0]);
        // 然后挨个从根节点开始插入
        for (int i = 1; i < preorder.length; ++i) insert(preorder[i], root);
        return root;
    }

    private void insert(int val, TreeNode root) {
        if (val < root.val) {
            // 如果 val 比当前子树根节点数值小，那么就插入该根节点的左子树
            // 不过在此之前需要先看看根节点的左子树是不是空的，如果是空的就直接放进来好了，如果不是的话，就需要递归插入
            if (root.left == null) root.left = new TreeNode(val);
            else insert(val, root.left);
        } else {
            // 思路同上，只不过是比较右子树节点了
            if (root.right == null) root.right = new TreeNode(val);
            else insert(val, root.right);
        }
    }

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
}
