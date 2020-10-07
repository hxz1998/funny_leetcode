/**
 * Created by Xiaozhong on 2020/8/14.
 * Copyright (c) 2020/8/14 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "queue"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> ans;

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        dfs(root->right);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root) {
        /* DFS深度优先搜索方法 */
        if (root) dfs(root);
        return ans;
    }
};