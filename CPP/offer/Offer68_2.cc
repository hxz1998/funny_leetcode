/*
 * Created by Xiaozhong on 12/22/2021.
 * Copyright (c) 12/22/2021 Xiaozhong. All rights reserved.
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
    TreeNode *ans = nullptr;
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }

private:
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return false;
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        if (left && right || left && (root->val == p->val || root->val == q->val) ||
            right && (root->val == p->val || root->val == q->val))
            ans = root;
        return left || right || root->val == p->val || root->val == q->val;
    }
};