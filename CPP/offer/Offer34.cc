/*
 * Created by Xiaozhong on 12/10/2021.
 * Copyright (c) 12/10/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "queue"

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
public:
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        vector<int> path;
        dfs(root, target, ans, path, 0);
        return ans;
    }

private:
    void dfs(TreeNode *root, int target, vector<vector<int>> &ans, vector<int> &path, int buffer) {
        buffer += root->val;
        path.emplace_back(root->val);
        if (target == buffer && root->left == nullptr && root->right == nullptr) {
            ans.emplace_back(vector<int>(path));
        }
        if (root->left != nullptr) dfs(root->left, target, ans, path, buffer);
        if (root->right != nullptr) dfs(root->right, target, ans, path, buffer);
        path.pop_back();
    }
};