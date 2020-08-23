/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
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
        int root_val = root->val;
        int p_val = p->val, q_val = q->val;
        if (p_val > root_val && q_val > root_val) return lowestCommonAncestor(root->right, p, q);
        else if (p_val < root_val && q_val < root_val) return lowestCommonAncestor(root->left, p, q);
        else return root;
    }
};