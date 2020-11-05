/**
 * Created by Xiaozhong on 2020/11/5.
 * Copyright (c) 2020/11/5 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_map>

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
    vector<TreeNode *> ans;
    unordered_map<string, int> count;

    string dfs(TreeNode *root) {
        if (!root) return "#";
        string buf = to_string(root->val) + "," + dfs(root->left) + "," + dfs(root->right);
        count[buf]++;
        if (count[buf] == 2) ans.emplace_back(root);
        return buf;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        dfs(root);
        return ans;
    }
};