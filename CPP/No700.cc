/**
 * Created by Xiaozhong on 2020/11/19.
 * Copyright (c) 2020/11/19 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode *dfs(TreeNode *root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        TreeNode *left_ret = nullptr, *right_ret = nullptr;
        if (root->left) left_ret = dfs(root->left, val);
        if (root->right) right_ret = dfs(root->right, val);
        return left_ret ? left_ret : right_ret ? right_ret : nullptr;
    }

public:
    TreeNode *searchBST(TreeNode *root, int val) {
        return dfs(root, val);
    }
};