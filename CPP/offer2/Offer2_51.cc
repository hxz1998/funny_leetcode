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

/*    int helper(TreeNode *root) {
        if (root == nullptr) return 0;
        else if (root->left == nullptr && root->right == nullptr) {
            ans = max(ans, root->val);
            return root->val;
        } else if (root->left == nullptr) {
            int right = helper(root->right);
            ans = max(ans, max(right, max(root->val, root->val + right)));
            return root->val + (right < 0 ? 0 : right);
        } else if (root->right == nullptr) {
            int left = helper(root->left);
            ans = max(ans, max(left, max(root->val, root->val + left)));
            return root->val + (left < 0 ? 0 : left);
        } else {
            int left = helper(root->left);
            int right = helper(root->right);
            ans = max(ans, max(left, max(right, root->val + (left < 0 ? 0 : left) + (right < 0 ? 0 : right))));
            return max((left < 0 ? 0 : 1) + root->val, (right < 0 ? 0 : 1) + root->val);
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