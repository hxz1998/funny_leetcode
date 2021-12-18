/**
 * Created by Xiaozhong on 2021/12/18.
 * Copyright (c) 2021/12/18 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isBalancedTree = true;
public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) return true;
        dfs(root, 1);
        return isBalancedTree;
    }

private:
    int dfs(TreeNode *root, int depth) {
        if (!isBalancedTree) return 0;
        if (root == nullptr) return depth;
        int left = dfs(root->left, depth + 1);
        int right = dfs(root->right, depth + 1);
        if (abs(right - left) > 1) isBalancedTree = false;
        return max(left, right);
    }
};