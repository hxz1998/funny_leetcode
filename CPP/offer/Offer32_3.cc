/*
 * Created by Xiaozhong on 12/10/2021.
 * Copyright (c) 12/10/2021 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "deque"

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
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        deque<TreeNode *> dq;
        dq.push_back(root);
        bool leftToRight = true;
        while (!dq.empty()) {
            int sz = dq.size();
            vector<int> buffer;
            if (leftToRight) {
                for (int i = 0; i < sz; ++i) {
                    TreeNode *node = dq.front();
                    dq.pop_front();
                    buffer.emplace_back(node->val);
                    if (node->left != nullptr) dq.push_back(node->left);
                    if (node->right != nullptr) dq.push_back(node->right);
                }
            } else {
                for (int i = 0; i < sz; ++i) {
                    TreeNode *node = dq.back();
                    dq.pop_back();
                    buffer.emplace_back(node->val);
                    if (node->right != nullptr) dq.push_front(node->right);
                    if (node->left != nullptr) dq.push_front(node->left);
                }
            }
            leftToRight = !leftToRight;
            ans.emplace_back(buffer);
        }
        return ans;
    }
};