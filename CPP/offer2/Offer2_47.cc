/**
 * Created by Xiaozhong on 2022/4/4.
 * Copyright (c) 2022/4/4 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

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
    bool dfs(TreeNode *root) {
        if (root == nullptr) return true;
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        if (left) root->left = nullptr;
        if (right) root->right = nullptr;
        return left && right && root->val == 0;
    }

public:
    TreeNode *pruneTree(TreeNode *root) {
        bool ret = dfs(root);
        return ret ? nullptr : root;
    }
};