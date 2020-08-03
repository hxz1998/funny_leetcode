/**
 * Created by Xiaozhong on 2020/8/3.
 * Copyright (c) 2020/8/3 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "simple_tree_node.h"
#include "vector"

using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return dfs(0, nums.size() - 1, nums);
    }

private:
    TreeNode *dfs(int left, int right, vector<int> &nums) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        auto *root = new TreeNode(nums[mid]);
        root->left = dfs(left, mid - 1, nums);
        root->right = dfs(mid + 1, right, nums);
        return root;
    }
};