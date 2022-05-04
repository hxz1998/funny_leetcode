/**
 * Created by Xiaozhong on 2022/3/15.
 * Copyright (c) 2022/3/15 Xiaozhong. All rights reserved.
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
    int ans = INT32_MIN;

/*    int helper(TreeNode *curr) {
        if (curr == nullptr) return 0;
        else if (curr->left == nullptr && curr->right == nullptr) {
            ans = max(ans, curr->val);
            return curr->val;
        } else if (curr->left == nullptr) {
            int right = helper(curr->right);
            ans = max(ans, max(right, max(curr->val, curr->val + right)));
            return curr->val + (right < 0 ? 0 : right);
        } else if (curr->right == nullptr) {
            int left = helper(curr->left);
            ans = max(ans, max(left, max(curr->val, curr->val + left)));
            return curr->val + (left < 0 ? 0 : left);
        } else {
            int left = helper(curr->left);
            int right = helper(curr->right);
            ans = max(ans, max(left, max(right, curr->val + (left < 0 ? 0 : left) + (right < 0 ? 0 : right))));
            return max((left < 0 ? 0 : 1) + curr->val, (right < 0 ? 0 : 1) + curr->val);
        }
    }*/

    int helper(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int mx = root->val + (left < 0 ? 0 : left) + (right < 0 ? 0 : right);
        ans = max(ans, mx);
        return max(root->val + (left < 0 ? 0 : left), root->val + (right < 0 ? 0 : right));
    }

public:

    int maxPathSum(TreeNode *root) {
        if (root == nullptr) return 0;
        helper(root);
        helper(root->left);
        helper(root->right);
        return ans;
    }
};