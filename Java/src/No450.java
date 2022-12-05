/**
 * Created by Xiaozhong on 2022/6/3.
 * Copyright (c) 2022/6/3 Xiaozhong. All rights reserved.
 */
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

class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if (null == root) return null;
        if (root.val < key) {
            root.right = deleteNode(root.right, key);
        } else if (root.val > key) {
            root.left = deleteNode(root.left, key);
        } else {
            if (null == root.left && null == root.right) return null;
            else if (null == root.left) return root.right;
            else if (null == root.right) return root.left;
            else {
                TreeNode successor = root.right;
                while (null != successor.left) successor = successor.left;
                root.right = deleteNode(root.right, successor.val);
                successor.left = root.left;
                successor.right = root.right;
                return successor;
            }
        }
        return root;
    }
}

public class No450 {

}
