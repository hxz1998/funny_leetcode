/**
 * Created by Xiaozhong on 2020/10/19.
 * Copyright (c) 2020/10/19 Xiaozhong. All rights reserved.
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
    int tilt = 0;

    int dfs(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        int sum_left = dfs(root->left);
        int sum_right = dfs(root->right);
        tilt += abs(sum_left - sum_right);
        return sum_left + sum_right + root->val;
    }

public:
    int findTilt(TreeNode *root) {
        dfs(root);
        return tilt;
    }
};