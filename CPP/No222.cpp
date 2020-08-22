/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void dfs(TreeNode *root, int &sum) {
        if (!root) return;
        sum++;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
public:
    int countNodes(TreeNode *root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
};