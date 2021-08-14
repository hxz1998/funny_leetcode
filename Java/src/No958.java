/*
 * Copyright (c) 8/14/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class No958 {
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

    public boolean isCompleteTree(TreeNode root) {
        List<AnnotatedNode> list = new ArrayList<>();
        list.add(new AnnotatedNode(root, 1));
        int idx = 0;
        while (idx < list.size()) {
            AnnotatedNode node = list.get(idx++);
            if (node.node != null) {
                list.add(new AnnotatedNode(node.node.left, node.code * 2));
                list.add(new AnnotatedNode(node.node.right, node.code * 2 + 1));
            }
        }
        return list.get(list.size() - 1).code == list.size();
    }

    private static class AnnotatedNode {
        TreeNode node;
        int code;

        AnnotatedNode(TreeNode node, int code) {
            this.node = node;
            this.code = code;
        }
    }

    public static void main(String[] args) {
        TreeNode node1 = new TreeNode(1), node2 = new TreeNode(2), node3 = new TreeNode(3),
                node5 = new TreeNode(5), node7 = new TreeNode(7), node8 = new TreeNode(8);
        node1.left = node2;
        node1.right = node3;
        node2.left = node5;
        node3.left = node7;
        node3.right = node8;
        No958 no958 = new No958();
        System.out.println(no958.isCompleteTree(node1));
    }
}
