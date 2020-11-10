/**
 * Created by Xiaozhong on 2020/11/10.
 * Copyright (c) 2020/11/10 Xiaozhong. All rights reserved.
 */
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
    // 什么？为什么要用 long long？还是不是因为有个测试用例是 [2,2,2147483647] /苦瓜脸
    long long min1, min2;

    void dfs(TreeNode *root) {
        // 检查非空以及当前子树根节点是否大于当前最小值（大于的话自然没必要再去处理）
        if (!root || root->val > min2) return;
        // 判断两个子树，在子树值小于 min2 的情况下，
        // 还需要保证子树的值不是第一小才能用它更新第二小
        if (root->left && root->left->val != min1) min2 = min((long long) root->left->val, min2);
        if (root->right && root->right->val != min1) min2 = min((long long) root->right->val, min2);
        dfs(root->left);
        dfs(root->right);
    }

public:
    int findSecondMinimumValue(TreeNode *root) {
        min1 = root->val;
        min2 = INT64_MAX;
        dfs(root);
        return min2 == INT64_MAX ? -1 : (int) min2;
    }
};