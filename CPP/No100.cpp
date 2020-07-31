/**
 * Created by Xiaozhong on 2020/7/31.
 * Copyright (c) 2020/7/31 Xiaozhong. All rights reserved.
 */
#include "simple_tree_node.h"

/*
 * Wow!!~~ \@.@/? 懵懵的，一百道了，七月的最后一天~老婆陪着俺一起刷到了 100 题 --<<@ 花花送老婆
 * 秃头 \^.^/
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // 递归 + 先序遍历
        if (!p && !q) return true;
        if ((!p && q) || (!q && p)) return false;
        // 先序遍历
        if (p->val != q->val) return false;
        // 递归
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
