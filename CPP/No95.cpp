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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    vector<TreeNode *> generateTrees(int start, int end) {
        if (start > end) { return {nullptr}; }
        vector<TreeNode *> ans;
        // 挨个枚举可使用的根节点
        for (int i = start; i <= end; i++) {
            // 先获取到根节点左侧可用的左节点
            vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
            // 再获取到根节点右侧可用的右节点
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);
            for (TreeNode *leftNode : leftTrees) {
                for (TreeNode *rightNode : rightTrees) {
                    // 挨个使用节点来构建二叉树
                    TreeNode *currentNode = new TreeNode(i);
                    currentNode->right = rightNode;
                    currentNode->left = leftNode;
                    ans.push_back(currentNode);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        if (!n) return {};
        return generateTrees(1, n);
    }
};

int main() {
    Solution s;
    vector<TreeNode *> ans = s.generateTrees(3);
    for (TreeNode *node : ans) {
        cout << node->val;
    }
}