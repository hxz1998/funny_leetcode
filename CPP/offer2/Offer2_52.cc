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
    TreeNode *curr;

    void inorder(TreeNode *root) {
        if (root == nullptr) return;
        inorder(root->left);
        root->left = nullptr;
        curr->right = root;
        curr = root;
        inorder(root->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        if (root == nullptr) return root;
        TreeNode *dummyHead = new TreeNode(-1);
        curr = dummyHead;
        inorder(root);
        return dummyHead->right;
    }
};