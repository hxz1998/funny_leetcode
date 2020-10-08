/**
 * Created by Xiaozhong on 2020/10/8.
 * Copyright (c) 2020/10/8 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 层序遍历，记录每层开始的第一个元素
    int findBottomLeftValue(TreeNode *root) {
        deque<TreeNode *> dq;
        dq.push_back(root); // 先把根节点放进来

        int ans = 0;        // 用来记录最终答案
        while (!dq.empty()) {       // 层序遍历
            int size = dq.size();
            ans = dq.front()->val;  // 记录下来这一层的第一个元素
            for (int i = 0; i < size; ++i) {
                TreeNode *node = dq.front();
                dq.pop_front();
                // 放进来当前节点的左右子节点
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
            }
        }
        return ans;
    }
};