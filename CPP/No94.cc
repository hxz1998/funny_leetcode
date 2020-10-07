/**
 * Created by Xiaozhong on 2020/7/30.
 * Copyright (c) 2020/7/30 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    vector<int> ans;

    void helper(TreeNode *root) {
        // 按照中序遍历的顺序，先遍历左侧，填充数据，再遍历右侧
        if (root != nullptr) {
            if (root->left != nullptr) {
                helper(root->left);
            }
            ans.push_back(root->val);
            if (root->right != nullptr) {
                helper(root->right);
            }
        }
    }

public:
    vector<int> inorderTraversal(TreeNode *root) {
        helper(root);
        return ans;
    }
};

int main() {
    Solution s;

}