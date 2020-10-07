/**
 * Created by Xiaozhong on 2020/8/7.
 * Copyright (c) 2020/8/7 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "simple_node.h"

using namespace std;

class Solution {
private:
    int max_sum = INT32_MIN;

    int helper(TreeNode *root) {
        // 临界值
        if (!root) return 0;
        int left_max = max(helper(root->left), 0);
        int right_max = max(helper(root->right), 0);
        int tmp_new_sum = root->val + left_max + right_max;
        max_sum = max(tmp_new_sum, max_sum);
        return root->val + max(left_max, right_max);
    }

public:
    int maxPathSum(TreeNode *root) {
        helper(root);
        return max_sum;
    }
};