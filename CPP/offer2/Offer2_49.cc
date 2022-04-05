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
    int ans = 0;

    void dfs(TreeNode *root, int buffer) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) ans += buffer * 10 + root->val;
        else {
            dfs(root->left, buffer * 10 + root->val);
            dfs(root->right, buffer * 10 + root->val);
        }
    }

public:
    int sumNumbers(TreeNode *root) {
        dfs(root, 0);
        return ans;
    }
};