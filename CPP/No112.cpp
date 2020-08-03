/**
 * Created by Xiaozhong on 2020/8/3.
 * Copyright (c) 2020/8/3 Xiaozhong. All rights reserved.
 */

#include "simple_node.h"
#include "iostream"

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        // 如果遇到了叶子节点，那么就检查结果是否符合要求
        if (!root->left && !root->right) return root->val == sum;
        // 递归检查左右子树
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};