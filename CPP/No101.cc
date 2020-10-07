/**
 * Created by Xiaozhong on 2020/8/1.
 * Copyright (c) 2020/8/1 Xiaozhong. All rights reserved.
 */
#include "simple_node.h"
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return helper(root, root);
    }

private:
    bool helper(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && helper(p->left, q->right) && helper(p->right, q->left);
    }
};
