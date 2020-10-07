/**
 * Created by Xiaozhong on 2020/8/28.
 * Copyright (c) 2020/8/28 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<TreeNode *, int> f, g;

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);    // 后序遍历
        dfs(root->right);
        f[root] = root->val + g[root->left] + g[root->right];   // 更新拿了 root 之后可以拿到的最大值
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);  // 不拿 root 之后的最大值
    }

public:
    int rob(TreeNode *root) {
        dfs(root);
        return max(g[root], f[root]);
    }
};