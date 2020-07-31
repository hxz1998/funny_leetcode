/**
 * Created by Xiaozhong on 2020/7/31.
 * Copyright (c) 2020/7/31 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include "simple_tree_node.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    long long pre = INT64_MIN;
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        // 访问左子树
        if (!isValidBST(root->left)) return false;
        // 放问当前节点，如果中序遍历下，当前节点小于了前一个节点，那么说明不符合要求，返回false
        if (root->val <= pre) return false;
        //更新前一个节点为当前值
        pre = root->val;
        // 最后放问右子树
        return isValidBST(root->right);
    }
};
