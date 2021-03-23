/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */


import java.util.ArrayList;
import java.util.List;

public class No99 {
    public void recoverTree(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        dfs(root, list);
        int[] nodes = getPosition(root, list);
        recover(root, nodes);
    }

    private void dfs(TreeNode root, List<Integer> list) {
        if (root == null) return;
        dfs(root.left, list);
        list.add(root.val);
        dfs(root.right, list);
    }

    private int[] getPosition(TreeNode root, List<Integer> list) {
        int x = -1, y = -1;
        for (int i = 0; i < list.size() - 1; ++i) {
            if (list.get(i) > list.get(i + 1)) {
                y = list.get(i + 1);
                if (x == -1) x = list.get(i);
                else break;
            }
        }
        return new int[]{x, y};
    }

    private void recover(TreeNode root, int[] position) {
        if (root == null) return;
        int x = position[0], y = position[1];
        if (root.val == x || root.val == y) {
            root.val = root.val == x ? y : x;
        }
        recover(root.left, position);
        recover(root.right, position);
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
