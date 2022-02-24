/*
 * Created by Xiaozhong on 2/24/2022.
 * Copyright (c) 2/24/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
class Solution {
private:
    void dfs(TreeNode *root, vector<int> &buffer) {
        if (root == nullptr) return;
        dfs(root->left, buffer);
        buffer.emplace_back(root->val);
        dfs(root->right, buffer);
    }

public:
    bool isValidBST(TreeNode *root) {
        vector<int> buffer;
        dfs(root, buffer);
        for (int idx = 0; idx < buffer.size() - 1; ++idx) {
            if (buffer[idx] >= buffer[idx + 1]) return false;
        }
        return true;
    }
};*/

class Solution {
private:
    bool helper(TreeNode *root, long long lower, long long upper) {
        if (root == nullptr) return true;
        if (root->val >= upper || root->val <= lower) return false;
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }

public:
    bool isValidBST(TreeNode *root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

