/**
 * Created by Xiaozhong on 2020/8/5.
 * Copyright (c) 2020/8/5 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "complex_node.h"

using namespace std;

class Solution {
public:
    void flatten(TreeNode *root) {
        preorder(root);
        int n = list.size();
        for (int i = 1; i < n; i++) {
            TreeNode *prev = list.at(i - 1), *curr = list.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }

private:
    vector<TreeNode *> list;

    void preorder(TreeNode *root) {
        if (!root) return;
        list.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
};