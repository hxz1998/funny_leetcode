/**
 * Created by Xiaozhong on 2020/9/14.
 * Copyright (c) 2020/9/14 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int ans = 0;

    void dfs(TreeNode *root) {
        if (!root) return;
        if (root->left) {
            if (root->left->left == nullptr && root->left->right == nullptr) ans += root->left->val;
            dfs(root->left);
        }
        if (root->right) {
            dfs(root->right);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode *root) {
        dfs(root);
        return ans;
    }
};

