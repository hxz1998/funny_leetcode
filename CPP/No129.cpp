/**
 * Created by Xiaozhong on 2020/8/8.
 * Copyright (c) 2020/8/8 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "simple_node.h"

using namespace std;

class Solution {
private:

    int dfs(TreeNode *root, int buf) {
        if (!root) return 0;
        int sum = buf * 10 + root->val;
        if (!root->left && !root->right) return sum;
        return dfs(root->left, sum) + dfs(root->right, sum);
    }

public:
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
};