/*
 * Created by Xiaozhong on 12/6/2021.
 * Copyright (c) 12/6/2021 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode *root) {
        if (root == nullptr) return vector<int>();
        // 广度优先搜索
        queue<TreeNode *> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front();
                q.pop();
                ans.emplace_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return ans;
    }
};