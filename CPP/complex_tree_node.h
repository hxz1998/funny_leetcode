/**
 * Created by Xiaozhong on 2020/7/31.
 * Copyright (c) 2020/7/31 Xiaozhong. All rights reserved.
 */

#ifndef CPP_COMPLEX_TREE_NODE_H
#define CPP_COMPLEX_TREE_NODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //CPP_COMPLEX_TREE_NODE_H
