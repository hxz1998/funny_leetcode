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
    int ans = INT32_MIN;

    void dfs(TreeNode *root, int depth) {
        if (root == nullptr) {
            ans = max(ans, depth);
            return;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

public:
    int maxDepth(TreeNode *root) {
        dfs(root, 0);
        return ans;
    }
};