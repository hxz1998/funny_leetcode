/**
 * Created by Xiaozhong on 2020/8/3.
 * Copyright (c) 2020/8/3 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "simple_node.h"

using namespace std;

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        // 如果左右子树均为空的，那么就说明到了叶子节点
        if ((!root->left) && (!root->right)) return 1;
        int min_depth = INT32_MAX;
        // 检查左右子树的最小值
        if (root->left) min_depth = min(minDepth(root->left), min_depth);
        if (root->right) min_depth = min(minDepth(root->right), min_depth);
        return 1 + min_depth;
    }
};

