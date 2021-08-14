/*
 * Copyright (c) 8/9/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class No545 {
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

    // 判断一个节点是不是叶子节点
    private boolean isLeaf(TreeNode root) {
        return root.left == null && root.right == null;
    }

    // 添加树中的叶子节点进来
    private void addLeaf(TreeNode root, List<Integer> list) {
        if (root == null) return;
        if (isLeaf(root)) list.add(root.val);
        addLeaf(root.left, list);
        addLeaf(root.right, list);
    }

    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if (root == null) return list;
        // 先把根节点放进来，但是前提要求根节点不能为叶子节点，否则在下面的处理中会重复添加
        if (!isLeaf(root)) list.add(root.val);
        // 然后添加左半部分
        TreeNode curr = root.left;
        while (curr != null) {
            if (!isLeaf(curr)) list.add(curr.val);
            if (curr.left != null) curr = curr.left;
            else curr = curr.right;
        }
        // 添加叶子节点
        addLeaf(root, list);
        // 在添加右半边的时候，需要注意使用栈来进行，因为需要逆序
        Stack<Integer> stack = new Stack<>();
        curr = root.right;
        while (curr != null) {
            if (!isLeaf(curr)) stack.push(curr.val);
            if (curr.right == null) curr = curr.left;
            else curr = curr.right;
        }
        while (!stack.isEmpty()) list.add(stack.pop());
        return list;
    }

    public static void main(String[] args) {
        TreeNode node4 = new TreeNode(4, null, null);
        TreeNode node3 = new TreeNode(3, null, null);
        TreeNode node2 = new TreeNode(2, node3, node4);
        TreeNode node1 = new TreeNode(1, null, node2);
        No545 no545 = new No545();
        System.out.println(no545.boundaryOfBinaryTree(node1));

    }
}
