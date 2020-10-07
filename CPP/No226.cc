/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        dfs(root->right);
        TreeNode *t = root->left;
        root->left = root->right;
        root->right = t;
    }

public:
    TreeNode *invertTree(TreeNode *root) {
        dfs(root);
        return root;
    }
};
