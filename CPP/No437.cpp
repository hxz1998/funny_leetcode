/**
 * Created by Xiaozhong on 2020/9/20.
 * Copyright (c) 2020/9/20 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int count = 0;

    void dfs(TreeNode *root, int target, int total, unordered_map<int, int> &mapper) {
        int sum = root->val + total;

        // 本身节点已经达到了 target
        if (sum == target) ++count;
        // 在当前节点查看前缀和
        if (mapper[sum - target] > 0) count += mapper[sum - target];
        if (root->left) {
            mapper[sum] = mapper[sum] + 1;
            dfs(root->left, target, sum, mapper);
            mapper[sum] = mapper[sum] - 1;  // 回溯
        }
        if (root->right) {
            mapper[sum] = mapper[sum] + 1;
            dfs(root->right, target, sum ,mapper);
            mapper[sum] = mapper[sum] - 1;  // 回溯
        }

    }

public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        unordered_map<int, int> mapper;
        dfs(root, sum, 0, mapper);
        return count;
    }
};