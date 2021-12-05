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
    TreeNode *mirrorTree(TreeNode *root) {
        if (root == nullptr) return root;
        TreeNode *t = root->left;
        root->left = root->right;
        root->right = t;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};