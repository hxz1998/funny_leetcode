/**
 * Created by Xiaozhong on 2020/8/5.
 * Copyright (c) 2020/8/5 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "simple_node.h"
#include "vector"

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> buffer;

    void dfs(TreeNode *root, int sum) {
        if (!root) return;
        buffer.push_back(root->val);
        if (root->val == sum && !root->left && !root->right) ans.push_back(buffer);
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        buffer.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        dfs(root, sum);
        return ans;
    }
};