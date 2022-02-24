/*
 * Created by Xiaozhong on 2/24/2022.
 * Copyright (c) 2/24/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

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
private:
    void dfs(TreeNode *root, vector<int> &inorder) {
        if (root == nullptr) return;
        dfs(root->left, inorder);
        inorder.emplace_back(root->val);
        dfs(root->right, inorder);
    }

public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
};