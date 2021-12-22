/*
 * Created by Xiaozhong on 12/17/2021.
 * Copyright (c) 12/17/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool found = false;
    int val = 0;
    int cnt = 0, target = 0;
public:
    int kthLargest(TreeNode *root, int k) {
        target = k;
        dfs(root);
        return val;
    }

private:
    void dfs(TreeNode *root) {
        if (found || root == nullptr) return;
        dfs(root->left);
        cnt++;
        if (cnt == target) {
            found = true;
            val = root->val;
        }
        dfs(root->right);
    }
};