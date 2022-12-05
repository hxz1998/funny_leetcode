/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/20
 **/
package org.example;

import java.util.HashSet;
import java.util.Set;

public class LCP44 {
    private class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    private Set<Integer> set = new HashSet<>();

    public int numColor(TreeNode root) {
        if (root == null) return 0;
        set.add(root.val);
        numColor(root.left);
        numColor(root.right);
        return set.size();
    }
}
