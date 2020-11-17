/**
 * Created by Xiaozhong on 2020/11/16.
 * Copyright (c) 2020/11/16 Xiaozhong. All rights reserved.
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
    int dfs(TreeNode *root, int &ans) {
        if (!root) return 0;
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        left = (root->left && root->left->val == root->val) ? left + 1 : 0;
        right = (root->right && root->right->val == root->val) ? right + 1 : 0;
        ans = max(ans, left + right);
        return max(left, right);
    }

public:
    int longestUnivaluePath(TreeNode *root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    cout << s.longestUnivaluePath(root) << endl;
    return 0;
}