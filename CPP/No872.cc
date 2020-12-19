/**
 * Created by Xiaozhong on 2020/12/19.
 * Copyright (c) 2020/12/19 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

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
private:
    void dfs(TreeNode *root, vector<int> &container) {
        if (!root) return;
        // 如果遇到了叶节点，那么就把叶节点的值放进来
        if (!root->left && !root->right) {
            container.push_back(root->val);
            return;
        }
        // 深度优先递归搜索，检查左右子节点
        dfs(root->left, container);
        dfs(root->right, container);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        // 存放两个树的叶节点序列
        vector<int> container1, container2;
        dfs(root1, container1);
        dfs(root2, container2);
        // 看看两个序列是否一样
        return container1 == container2;
    }
};