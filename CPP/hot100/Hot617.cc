/*
 * Created by Xiaozhong on 3/3/2022.
 * Copyright (c) 3/3/2022 Xiaozhong. All rights reserved.
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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr) return root2;
        else if (root2 == nullptr) return root1;
        else {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root2->right, root2->right);
            return root1;
        }
    }
};