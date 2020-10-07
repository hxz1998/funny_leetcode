/**
 * Created by Xiaozhong on 2020/9/24.
 * Copyright (c) 2020/9/24 Xiaozhong. All rights reserved.
 */
#include "iostream"

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
    // 找后继节点的值：右 - 左 - 左 - 左 - 左...
    int successor(TreeNode *root) {
        root = root->right;
        while (root->left != nullptr) root = root->left;
        return root->val;
    }

    // 找先驱节点的值：左 - 右 - 右 - 右 - 右...
    int predecessor(TreeNode *root) {
        root = root->left;
        while (root->right != nullptr) root = root->right;
        return root->val;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return nullptr;
        // 删除左子树中的某一个节点
        if (key < root->val) root->left = deleteNode(root->left, key);
        // 删除右子树中的某一个节点
        else if (key > root->val) root->right = deleteNode(root->right, key);
        // 找到了节点所在的位置，就地删除
        else {
            // 当前节点是一个叶子节点
            if (root->left == nullptr && root->right == nullptr) root = nullptr;
            else if (root->right != nullptr) {
                // 当前节点的右节点不是空的
                root->val = successor(root); // 获取后继节点
                root->right = deleteNode(root->right, root->val); // 递归删除右子树
            } else {
                // 当前节点的左子树不是空的
                root->val = predecessor(root); // 获取前驱节点的值
                root->left = deleteNode(root->left, root->val); // 递归删除左子树
            }
        }
        return root;
    }
};