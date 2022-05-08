/**
 * Created by Xiaozhong on 2022/5/5.
 * Copyright (c) 2022/5/5 Xiaozhong. All rights reserved.
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
    int ans = 0;

    void dfs(TreeNode *root, int path, int target) {
        if (root == nullptr) return;
        if (path + root->val == target) {
            ans++;
        }
        dfs(root->left, path + root->val, target);
        dfs(root->right, path + root->val, target);
    }

public:
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return 0;
        dfs(root, 0, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }
};