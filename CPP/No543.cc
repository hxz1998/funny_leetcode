/**
 * Created by Xiaozhong on 2020/10/15.
 * Copyright (c) 2020/10/15 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int ans = 1;

    int dfs(TreeNode *root) {
        if (!root) return 0;
        int lheight = dfs(root->left), rheight = dfs(root->right);
        int height = lheight + rheight;
        ans = max(ans, height + 1);
        return max(lheight, rheight) + 1;
    }

public:
    // 左子树高度 + 右子树高度
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        dfs(root);
        return ans - 1;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << s.diameterOfBinaryTree(root);
}