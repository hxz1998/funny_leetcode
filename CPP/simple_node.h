/**
 * Created by Xiaozhong on 2020/7/31.
 * Copyright (c) 2020/7/31 Xiaozhong. All rights reserved.
 */

#ifndef CPP_SIMPLE_NODE_H
#define CPP_SIMPLE_NODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};
#endif //CPP_SIMPLE_NODE_H
