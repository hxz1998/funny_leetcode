/**
 * Created by Xiaozhong on 2020/8/2.
 * Copyright (c) 2020/8/2 Xiaozhong. All rights reserved.
 */

#include <vector>
#include "simple_node.h"
#include <queue>

using namespace std;

class Solution {
private:
    deque<TreeNode *> q;
    vector<vector<int>> ans;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return ans;
        q.push_front(root);
        bool odd = true;    // 标志位，判断是奇数行还是偶数行
        while (!q.empty()) {
            int length = q.size();
            vector<int> layer;
            for (int i = 0; i < length; i++) {
                if (odd) {  // 如果是奇数行，那么就取到队首节点，然后从左向右压入队尾
                    TreeNode *node = q.front();
                    q.pop_front();
                    layer.push_back(node->val);
                    if (node->left) q.push_back(node->left);
                    if (node->right) q.push_back(node->right);
                } else {    // 如果是偶数行，那么就取队尾节点，然后从右向左压入队首
                    TreeNode *node = q.back();
                    q.pop_back();
                    layer.push_back(node->val);
                    if (node->right) q.push_front(node->right);
                    if (node->left) q.push_front(node->left);
                }
            }
            odd = !odd;
            ans.push_back(layer);
        }
        return ans;
    }
};