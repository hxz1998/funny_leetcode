/**
 * Created by Xiaozhong on 2021/12/25.
 * Copyright (c) 2021/12/25 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "queue"

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
    bool isEvenOddTree(TreeNode *root) {
        if (root == nullptr) return true;
        int currLevel = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int prev = currLevel % 2 == 0 ? INT32_MIN : INT32_MAX;
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (currLevel % 2 == node->val % 2) return false;
                if (currLevel % 2 == 0) {
                    if (node->val <= prev) return false;
                    else prev = node->val;
                } else {
                    if (node->val >= prev) return false;
                    else prev = node->val;
                }
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return true;
    }
};

int main() {
    TreeNode *node = new TreeNode(2);
    Solution s;
    cout << s.isEvenOddTree(node) << endl;
}