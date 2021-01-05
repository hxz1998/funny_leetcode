/**
 * Created by Xiaozhong on 2020/12/30.
 * Copyright (c) 2020/12/30 Xiaozhong. All rights reserved.
 */

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
    TreeNode *pruneTree(TreeNode *root) {
        return containsOne(root) ? root : nullptr;
    }

private:
    bool containsOne(TreeNode *root) {
        if (root == nullptr) return false;
        bool a1 = containsOne(root->left);
        bool a2 = containsOne(root->right);
        if (!a1) root->left = nullptr;
        if (!a2) root->right = nullptr;
        return root->val == 1 || a1 || a2;
    }
};