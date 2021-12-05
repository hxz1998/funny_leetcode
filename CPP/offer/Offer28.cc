/**
 * Created by Xiaozhong on 2021/12/5.
 * Copyright (c) 2021/12/5 Xiaozhong. All rights reserved.
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
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return dfs(root->left, root->right);
    }

private:
    bool dfs(TreeNode *lhs, TreeNode *rhs) {
        if (lhs == nullptr && rhs == nullptr) return true;
        if (lhs == nullptr || rhs == nullptr) return false;
        if (lhs->val != rhs->val) return false;
        if (!dfs(lhs->left, rhs->right) || !dfs(lhs->right, rhs->left)) return false;
        return true;
    }
};