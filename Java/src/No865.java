/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No865 {
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

    // 用来存储每一个节点的深度
    private Map<TreeNode, Integer> mapper = new HashMap<>();
    // 记录下来最大深度
    private int maxDepth;

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        mapper.put(null, -1);
        dfs(root, null);
        maxDepth = -1;
        // 找到所有深度中的最大深度
        for (int value : mapper.values()) {
            maxDepth = Math.max(maxDepth, value);
        }
        // 找到符合深度要求的节点，并且返回
        return calc(root);
    }

    private void dfs(TreeNode node, TreeNode par) {
        if (node == null) return;
        mapper.put(node, mapper.get(par) + 1);
        dfs(node.left, node);
        dfs(node.right, node);
    }

    private TreeNode calc(TreeNode node) {
        // 如果当前节点为空，那么就直接返回他自己
        // 如果当前节点不为空而且深度正好是最深深度，那么也返回该节点
        if (node == null || mapper.get(node) == maxDepth) return node;
        // 检查左右子树
        TreeNode left = calc(node.left), right = calc(node.right);
        // 如果左右子树均不为空，那么说明该节点的左右子节点正好是所要找的根节点
        if (left != null && right != null) return node;
        // 如果只有左子树不为空，那么就返回左子树
        if (left != null) return left;
        // 否则就返回右子树
        if (right != null) return right;
        // 如果都是空的，那么就返回空
        return null;
    }
}
