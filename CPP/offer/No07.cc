/*
 * Created by Xiaozhong on 12/1/2021.
 * Copyright (c) 12/1/2021 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"
#include "unordered_map"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        for (int idx = 0; idx < inorder.size(); ++idx) mapper[inorder[idx]] = idx;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    unordered_map<int, int> mapper;

    TreeNode *
    build(const vector<int> &preorder, const vector<int> &inorder, int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft > preRight) return nullptr;
        TreeNode *root = new TreeNode(preorder[preLeft]);
        int idx = mapper[preorder[preLeft]];
        int leftSize = idx - inLeft;
        root->left = build(preorder, inorder, preLeft + 1, preLeft + leftSize, inLeft, idx - 1);
        root->right = build(preorder, inorder, preLeft + leftSize + 1, preRight, idx + 1, inRight);
        return root;
    }
};