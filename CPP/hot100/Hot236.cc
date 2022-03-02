/*
 * Created by Xiaozhong on 3/2/2022.
 * Copyright (c) 3/2/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *ans = nullptr;

    bool helper(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || ans != nullptr) return false;
        bool left = helper(root->left, p, q);
        bool right = helper(root->right, p, q);
        if (left && right || (left || right) && (root == p || root == q)) ans = root;
        return root == p || root == q || left || right;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        helper(root, p, q);
        return ans;
    }
};