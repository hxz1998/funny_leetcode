/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class No993 {
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

    public boolean isCousins(TreeNode root, int x, int y) {
        Queue<TreeNode> queue = new LinkedList<>();
        Map<TreeNode, TreeNode> parent = new HashMap<>();
        TreeNode xFlag = null, yFlag = null;
        queue.offer(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode node = queue.poll();
                if (node.left != null) {
                    parent.put(node.left, node);
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    parent.put(node.right, node);
                    queue.offer(node.right);
                }
                if (node.val == x) xFlag = node;
                if (node.val == y) yFlag = node;
                if (xFlag != null && yFlag != null && parent.get(xFlag) != parent.get(yFlag)) return true;
            }
            xFlag = null;
            yFlag = null;
        }
        return false;
    }
}
