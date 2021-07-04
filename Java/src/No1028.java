/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No1028 {
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

    public TreeNode recoverFromPreorder(String S) {
        Stack<TreeNode> stack = new Stack<>();
        char[] cs = S.toCharArray();
        int idx = 0, n = cs.length;
        while (idx < n) {
            int depth = 0, value = 0;
            while (idx < n && cs[idx] == '-') {
                depth++;
                idx++;
            }
            while (idx < n && cs[idx] != '-') {
                value = value * 10 + (cs[idx] - '0');
                idx++;
            }
            TreeNode node = new TreeNode(value);
            if (!stack.isEmpty()) {
                while (stack.size() > depth) stack.pop();
                TreeNode parent = stack.peek();
                if (parent.left == null) parent.left = node;
                else parent.right = node;
            }
            stack.push(node);
        }
        while (stack.size() > 1) stack.pop();
        return stack.pop();
    }

    public static void main(String[] args) {
        No1028 no1028 = new No1028();
        no1028.recoverFromPreorder("1-2--3--4-5--6--7");
    }
}
