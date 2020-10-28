/**
 * Created by Xiaozhong on 2020/10/28.
 * Copyright (c) 2020/10/28 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    string tree2str(TreeNode *t) {
        if (!t) return "";
        if (!t->left && !t->right) return to_string(t->val);
        if (!t->right) return to_string(t->val).append("(" + tree2str(t->left) + ")");
        return to_string(t->val).append("(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")");
    }
};
