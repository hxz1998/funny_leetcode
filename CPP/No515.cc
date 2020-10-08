/**
 * Created by Xiaozhong on 2020/10/8.
 * Copyright (c) 2020/10/8 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <queue>

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
public:
    // 仍然层序遍历
    vector<int> largestValues(TreeNode *root) {
        // 边界条件处理
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        // 层序遍历
        while (!q.empty()) {
            int size = q.size();
            int num = INT32_MIN;    // 用来记录这一层中最大的值
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                num = max(num, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(num);     // 把这一层中最大的值存下来
        }
        return ans;
    }
};