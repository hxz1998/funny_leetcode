/*
 * Created by Xiaozhong on 12/6/2021.
 * Copyright (c) 12/6/2021 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "queue"
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> layer;
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front();
                q.pop();
                layer.emplace_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            ans.emplace_back(layer);
        }
        return ans;
    }
};