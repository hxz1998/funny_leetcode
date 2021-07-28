/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No156 {
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

    public TreeNode upsideDownBinaryTree(TreeNode root) {
        TreeNode right = null, father = null;
        while (root != null) {
            // 先记录下来左子节点
            TreeNode left = root.left;
            // 当前根节点的左子节点为父节点的右子节点
            root.left = right;
            // 右子节点记录下来当前根节点的右子节点
            right = root.right;
            // 当前根节点的右子节点是父节点
            root.right = father;
            // 记录下来新的父节点，继续向下遍历
            father = root;
            // 更新根节点是 左子节点
            root = left;
        }
        return father;
    }
}
