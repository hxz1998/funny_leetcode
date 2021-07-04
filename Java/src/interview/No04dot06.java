/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.List;

public class No04dot06 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
    private List<TreeNode> list;
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        list = new ArrayList<>();
        inorder(root);
        for (int i = 0; i < list.size(); ++i) {
            if (list.get(i) == p) return i < list.size() - 1 ? list.get(i + 1) : null;
        }
        return null;
    }

    private void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        list.add(root);
        inorder(root.right);
    }
}
