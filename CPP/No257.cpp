/**
 * Created by Xiaozhong on 2020/8/24.
 * Copyright (c) 2020/8/24 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<string> ans;

    void dfs(TreeNode *root, string buffer) {
        if (!root) return;
        buffer.append("->" + to_string(root->val));
        if (!root->left && !root->right) ans.push_back(buffer.substr(2));
        dfs(root->left, buffer);
        dfs(root->right, buffer);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root) {
        dfs(root, "");
        return ans;
    }
};