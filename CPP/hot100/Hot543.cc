/**
 * Created by Xiaozhong on 2022/3/1.
 * Copyright (c) 2022/3/1 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "algorithm"

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
    int max1 = 0, max2 = 0;

    void dfs(TreeNode *root, int height) {
        if (root == nullptr) return;
        dfs(root->left, height + 1);
        dfs(root->right, height + 1);
        max2 = height <= max1 && height > max2 ? height : max2;
        max1 = max(max1, height);
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {

    }
};