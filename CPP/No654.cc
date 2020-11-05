/**
 * Created by Xiaozhong on 2020/11/6.
 * Copyright (c) 2020/11/6 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int max_index(const vector<int> &nums, int left, int right) {
        int max_index = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] > nums[max_index]) max_index = i;
        }
        return max_index;
    }

    TreeNode *construct(const vector<int> &nums, int left, int right) {
        if (left == right) return nullptr;
        int max_idx = max_index(nums, left, right);
        TreeNode *node = new TreeNode(nums[max_idx]);
        node->left = construct(nums, left, max_idx);
        node->right = construct(nums, max_idx + 1, right);
        return node;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return construct(nums, 0, nums.size());
    }
};