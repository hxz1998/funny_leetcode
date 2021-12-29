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
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val > q->val) {
            TreeNode *tmp = p;
            p = q;
            q = tmp;
        }
        while (root != nullptr) {
            if (root->val > q->val) root = root->left;
            else if (root->val < p->val) root = root->right;
            else break;
        }
        return root;
    }
};