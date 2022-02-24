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
    bool helper(TreeNode *lhs, TreeNode *rhs) {
        if (lhs == nullptr && rhs != nullptr || lhs != nullptr && rhs == nullptr) return false;
        if (lhs == nullptr && rhs == nullptr) return true;
        if (lhs->val == rhs->val) return helper(lhs->left, rhs->right) && helper(lhs->right, rhs->left);
        return false;
    }

public:
    bool isSymmetric(TreeNode *root) {
        return helper(root->left, root->right);
    }
};