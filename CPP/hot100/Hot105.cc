/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "unordered_map"

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
    TreeNode *helper(const vector<int> &preorder, const vector<int> &inorder,
                     const unordered_map<int, int> &mapper,
                     int preorderLeft, int preorderRight, int inorderLeft, int inorderRight) {
        if (preorderLeft > preorderRight) return nullptr;
        int rootIndex = mapper.at(preorder[preorderLeft]);
        int leftSubtreeSize = rootIndex - inorderLeft;
        auto *node = new TreeNode(preorder[preorderLeft]);
        node->left = helper(preorder, inorder, mapper, preorderLeft + 1, preorderLeft + leftSubtreeSize,
                            inorderLeft, rootIndex - 1);
        node->right = helper(preorder, inorder, mapper, preorderLeft + leftSubtreeSize + 1, preorderRight,
                             rootIndex + 1, inorderRight);
        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        unordered_map<int, int> mapper;
        for (int idx = 0; idx < inorder.size(); ++idx) mapper[inorder[idx]] = idx;
        return helper(preorder, inorder, mapper, 0, n - 1, 0, n - 1);
    }
};