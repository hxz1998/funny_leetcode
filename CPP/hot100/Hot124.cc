/*
 * Created by Xiaozhong on 3/10/2022.
 * Copyright (c) 3/10/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

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
    int ans = INT32_MIN;

    int dfs(TreeNode *root) {
        if (root == nullptr) return INT32_MIN;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }

public:
    int maxPathSum(TreeNode *root) {
        dfs(root);
        return ans;
    }
};