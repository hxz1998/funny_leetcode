/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lccup2021;

import java.util.PriorityQueue;

public class Group2 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    PriorityQueue<Integer> pq;

    public int maxValue(TreeNode root, int k) {
        pq = new PriorityQueue<>((o1, o2) -> o2 - o1);
        addAll(root);
        return 0;
    }

    private void addAll(TreeNode root) {
        if (root == null) return;
        pq.add(root.val);
        addAll(root.left);
        addAll(root.right);
    }
}
