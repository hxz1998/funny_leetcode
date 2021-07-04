/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.List;

public class No04dot10 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
        if (t1 == null) return false;
        if (t2 == null) return true;
        return check(t1, t2) || checkSubTree(t1.left, t2) || checkSubTree(t1.right, t2);
    }

    private boolean check(TreeNode t1, TreeNode t2) {
        if (t1 == null || t2 == null) return true;
        if (t1.val != t2.val) return false;
        return check(t1.left, t2.left) && check(t1.right, t2.right);
    }
//    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
//        List<Integer> preOrder1 = new ArrayList<>(), preOrder2 = new ArrayList<>();
//        dfs(t1, preOrder1);
//        dfs(t2, preOrder2);
//        String order1 = preOrder1.toString();
//        String order2 = preOrder2.toString();
//        return order1.contains(order2.substring(1, order2.length() - 1));
//    }
//
//    private void dfs(TreeNode t1, List<Integer> preOrder) {
//        if (t1 == null) {
//            preOrder.add(null);
//            return;
//        }
//        preOrder.add(t1.val);
//        dfs(t1.left, preOrder);
//        dfs(t1.right, preOrder);
//    }


}
