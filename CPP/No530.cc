/**
 * Created by Xiaozhong on 2020/10/12.
 * Copyright (c) 2020/10/12 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int ans = INT32_MAX;
    int prev = -1, curr = 0;

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        curr = root->val;
        if (prev != -1) {
            ans = min(curr - prev, ans);
        }
        prev = curr;
        dfs(root->right);
    }

public:
    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return ans;
    }
};