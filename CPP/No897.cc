/**
 * Created by Xiaozhong on 2020/12/31.
 * Copyright (c) 2020/12/31 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

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
    void inOrder(TreeNode *root, vector<int> &res) {
        if (root == NULL) return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }

    TreeNode *increasingBST(TreeNode *root) {
        vector<int> res;
        inOrder(root, res);
        TreeNode *ans = new TreeNode(0), *cur = ans;
        for (int v:res) {
            cur->right = new TreeNode(v);
            cur = cur->right;
        }

        return ans->right;
    }
};