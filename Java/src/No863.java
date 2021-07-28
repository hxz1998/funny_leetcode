/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;


public class No863 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    Map<Integer, TreeNode> parents;
    List<Integer> ans;

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        parents = new HashMap<>();
        ans = new ArrayList<>();
        findParents(root);
        findAns(target, 0, null, k);
        return ans;
    }

    private void findAns(TreeNode root, int distance, TreeNode from, int k) {
        if (root == null) return;
        if (distance == k) {
            ans.add(root.val);
            return;
        }
        if (root.left != from) findAns(root.left, distance + 1, root, k);
        if (root.right != from) findAns(root.right, distance + 1, root, k);
        if (parents.get(root.val) != from) findAns(parents.get(root.val), distance + 1, root, k);
    }

    private void findParents(TreeNode root) {
        if (root.left != null) {
            parents.put(root.left.val, root);
            findParents(root.left);
        }
        if (root.right != null) {
            parents.put(root.right.val, root);
            findParents(root.right);
        }
    }
}
