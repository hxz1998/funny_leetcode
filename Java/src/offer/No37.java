/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package offer;

import java.util.LinkedList;
import java.util.Queue;

public class No37 {
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    class Codec {

        // Encodes a tree to a single string.
        public String serialize(TreeNode root) {
            StringBuilder builder = new StringBuilder();
            Queue<TreeNode> queue = new LinkedList<>();
            queue.offer(root);
            while (!queue.isEmpty()) {
                int size = queue.size();
                while (size-- > 0) {
                    TreeNode node = queue.poll();
                    if (node == null) builder.append("-.");
                    else {
                        builder.append(node.val).append(".");
                        queue.offer(node.left);
                        queue.offer(node.right);
                    }
                }
            }
            return builder.toString();
        }

        // Decodes your encoded data to tree.
        public TreeNode deserialize(String data) {
            Queue<TreeNode> queue = new LinkedList<>();
            String[] items = data.split("\\.");
            TreeNode root;
            if (items[0].equals("-")) {
                return null;
            } else {
                root = new TreeNode(Integer.parseInt(items[0]));
                queue.offer(root);
            }
            int idx = 1;
            while (!queue.isEmpty()) {
                int size = queue.size();
                while (size-- > 0) {
                    TreeNode curr = queue.poll();
                    if (curr != null) {
                        if (!items[idx].equals("-")) {
                            curr.left = new TreeNode(Integer.parseInt(items[idx]));
                            queue.offer(curr.left);
                        }
                        idx++;
                        if (!items[idx].equals("-")) {
                            curr.right = new TreeNode(Integer.parseInt(items[idx]));
                            queue.offer(curr.right);
                        }
                        idx++;
                    }
                }
            }
            return root;
        }
    }
}
