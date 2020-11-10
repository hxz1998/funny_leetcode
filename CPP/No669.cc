/**
 * Created by Xiaozhong on 2020/11/10.
 * Copyright (c) 2020/11/10 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode *dfs(TreeNode *root, int low, int high) {
        if (!root) return nullptr;
        if (root->val > high) return dfs(root->left, low, high);
        else if (root->val < low) return dfs(root->right, low, high);
        else {
            root->left = dfs(root->left, low, high);
            root->right = dfs(root->right, low, high);
        }
        return root;
    }

public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        return dfs(root, low, high);
    }
};