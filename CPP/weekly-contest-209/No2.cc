/**
 * Created by Xiaozhong on 2020/10/4.
 * Copyright (c) 2020/10/4 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <deque>

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
    // 层序遍历
    bool isEvenOddTree(TreeNode *root) {
        if (!root) return false;
        bool odd = true;
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty()) { // 控制每层
            int size = dq.size(), prev = 0;
            for (int i = 0; i < size; ++i) {    // 对该层进行遍历
                TreeNode *node = dq.front();    // 取出来队头元素
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
                dq.pop_front();
                if (odd) {
                    if (!(node->val & 1)) return false;
                    if (node->val <= prev && prev != 0) return false;
                    prev = node->val;
                } else if (!odd) {
                    if (node->val & 1) return false;
                    if (node->val >= prev && prev != 0) return false;
                    prev = node->val;
                }
            }
            odd = !odd;
        }
        return true;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(7);
    cout << s.isEvenOddTree(root) << endl;
}