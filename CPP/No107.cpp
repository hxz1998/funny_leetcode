/**
 * Created by Xiaozhong on 2020/8/3.
 * Copyright (c) 2020/8/3 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "simple_tree_node.h"
#include "queue"
#include "algorithm"

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    queue<TreeNode *> q;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return ans;
        q.push(root);
        while (!q.empty()) {
            int length = q.size();
            vector<int> buffer;
            for (int i = 0; i < length; i++) {
                TreeNode *node = q.front();
                q.pop();
                buffer.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(buffer);
        }
        // 翻转一下子
        reverse(ans.begin(), ans.end());
        return ans;
    }
};