/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
 */
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
    vector<int> inorder;

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        dfs(root);
        return inorder[k - 1];
    }
};