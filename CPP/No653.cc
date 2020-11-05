/**
 * Created by Xiaozhong on 2020/11/5.
 * Copyright (c) 2020/11/5 Xiaozhong. All rights reserved.
 */
#include <unordered_set>

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
    unordered_set<int> us;

    bool dfs(TreeNode *root, int k) {
        if (us.count(k - root->val)) return true;
        us.insert(root->val);
        bool res;
        if (root->left && dfs(root->left, k)) return true;
        if (root->right && dfs(root->right, k)) return true;
        return false;
    };
public:
    bool findTarget(TreeNode *root, int k) {
        if (root) return dfs(root, k);
        return false;
    }
};