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
    int ans = 0;

    int depth(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        depth(root);
        return ans;
    }
};