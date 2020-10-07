/**
 * Created by Xiaozhong on 2020/8/3.
 * Copyright (c) 2020/8/3 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "simple_node.h"

using namespace std;

class Solution {
private:
    int helper(TreeNode *root) {
        // 状态判断
        if (!root) return 0;
        return 1 + max(helper(root->left), helper(root->right));
    }

public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        // 每一棵子树都是一个子问题，所以需要对左右子树进行递归检查
        return abs(helper(root->left) - helper(root->right)) < 2 &&
               isBalanced(root->right) &&
               isBalanced(root->left);
    }
};