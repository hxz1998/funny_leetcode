/**
 * Created by Xiaozhong on 2020/8/2.
 * Copyright (c) 2020/8/2 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "simple_node.h"
#include "unordered_map"

using namespace std;

class Solution {
private:
    unordered_map<int, int> index;

    TreeNode *
    helper(vector<int> &preorder, vector<int> &inorder, int preorder_left, int preorder_right, int inorder_left,
           int inorder_right) {
        // 递归终止条件
        if (preorder_left > preorder_right) return nullptr;
        // 先把根节点给构造出来
        auto *root = new TreeNode(preorder[preorder_left]);
        // 根据先序遍历结果的第一个元素，来获取在中序遍历中的位置，并且根据该位置进行左右划分成两个子树（左右子树)
        int inorder_root = index[preorder[preorder_left]];
        int left_subtree_size = inorder_root - inorder_left;
        // 构造左子树，从 左边界+1 开始的 size_left_subtree 个元素就对应了中序遍历中 从 左边界 开始到 根节点定位-1 的元素
        root->left = helper(preorder, inorder, preorder_left + 1, preorder_left + left_subtree_size, inorder_left,
                            inorder_root - 1);
        // 同理，构造右子树
        root->right = helper(preorder, inorder, preorder_left + left_subtree_size + 1, preorder_right, inorder_root + 1,
                             inorder_right);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        // 建立映射
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};