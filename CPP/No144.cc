/**
 * Created by Xiaozhong on 2020/8/14.
 * Copyright (c) 2020/8/14 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> ans;

    void dfs(TreeNode *root) {
        if (!root) return;
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

public:
    vector<int> preorderTraversal(TreeNode *root) {
        /* 递归方法，深度优先搜索
         * if (root) dfs(root);
         */
        if (!root) return ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            ans.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        return ans;
    }
};

int main() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->left = nullptr;
    t1->right = t2;
    t2->left = t3;
    Solution s;
    vector<int> ans = s.preorderTraversal(t1);
    for (int i : ans) {
        cout << i << " ";
    }

}
