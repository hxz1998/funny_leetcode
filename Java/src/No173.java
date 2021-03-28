/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */


import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

class BSTIterator {
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

    List<Integer> data;
    Iterator<Integer> iterator;

    public BSTIterator(TreeNode root) {
        data = new ArrayList<>();
        dfs(root);
        iterator = data.iterator();
    }

    private void dfs(TreeNode root) {
        if (root == null) return;
        dfs(root.left);
        data.add(root.val);
        dfs(root.right);
    }

    public int next() {
        return iterator.next();
    }

    public boolean hasNext() {
        return iterator.hasNext();
    }
}

public class No173 {

}
