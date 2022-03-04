/*
 * Created by Xiaozhong on 3/4/2022.
 * Copyright (c) 3/4/2022 Xiaozhong. All rights reserved.
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
    vector<TreeNode *> inorder;

    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        dfs(root->left);
        inorder.emplace_back(root);
        dfs(root->right);
    }

public:
    TreeNode *convertBST(TreeNode *root) {
        dfs(root);
        for (int idx = inorder.size() - 2; idx >= 0; --idx) {
            inorder[idx]->val += inorder[idx + 1]->val;
        }
        return root;
    }
};