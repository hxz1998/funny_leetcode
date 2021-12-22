/*
 * Created by Xiaozhong on 12/17/2021.
 * Copyright (c) 12/17/2021 Xiaozhong. All rights reserved.
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
private:
    int ans = 0;
public:
    int maxDepth(TreeNode *root) {
        dfs(root, 0);
    }

private:
    void dfs(TreeNode *root, int depth) {
        if (root == nullptr) {
            ans = max(ans, depth);
            return;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};