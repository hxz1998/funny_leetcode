/**
 * Created by Xiaozhong on 2020/8/2.
 * Copyright (c) 2020/8/2 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <queue>
#include "simple_node.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) return ans;
        q.push(root);
        while (!q.empty()) {
            int length = q.size();
            ans.push_back(vector<int>());
            for (int i = 0; i < length; i++) {
                TreeNode *node = q.front();
                ans.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
        }
        return ans;
    }

private:
    vector<vector<int>> ans;
    queue<TreeNode *> q;
};