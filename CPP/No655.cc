/**
 * Created by Xiaozhong on 2020/11/6.
 * Copyright (c) 2020/11/6 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void fill(vector<vector<string>> &res, TreeNode *root, int i, int l, int r) {
        if (!root) return;
        res[i][(l + r) / 2] = to_string(root->val);
        fill(res, root->left, i + 1, l, (l + r) / 2);
        fill(res, root->right, i + 1, (l + r + 1) / 2, r);
    }

    int getHeight(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

public:
    vector<vector<string>> printTree(TreeNode *root) {
        int height = getHeight(root);
        vector<vector<string>> res(height, vector<string>((1 << height) - 1, ""));
        fill(res, root, 0, 0, res.front().size());
        return res;
    }
};