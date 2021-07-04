/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No437 {
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

    private Map<Integer, Integer> mapper = new HashMap<>();
    private int count = 0;
    private int targetSum = 0;

    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) return 0;
        this.targetSum = targetSum;
        dfs(root, 0);
        return count;
    }

    private void dfs(TreeNode root, int curr) {
        int sum = curr + root.val;
        if (sum == targetSum) count++;
        // 下面这句有疑问
        // 现在没了，因为是前缀和，需要在前面找到 sum - prev = target 的 prev
        if (mapper.containsKey(sum - targetSum)) count += mapper.get(sum - targetSum);
        if (root.left != null) {
            mapper.put(sum, mapper.getOrDefault(sum, 0) + 1);
            dfs(root.left, sum);
            mapper.put(sum, mapper.getOrDefault(sum, 0) - 1);
        }
        if (root.right != null) {
            mapper.put(sum, mapper.getOrDefault(sum, 0) + 1);
            dfs(root.right, sum);
            mapper.put(sum, mapper.getOrDefault(sum, 0) - 1);
        }
    }
}
