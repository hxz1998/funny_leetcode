/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
class Solution {
private:
    void dfs(TreeNode *root, queue<TreeNode *> &q) {
        if (root == nullptr) return;
        q.push(root);
        dfs(root->left, q);
        dfs(root->right, q);
    }

public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        queue<TreeNode *> q;
        dfs(root, q);
        TreeNode *prev = q.front();
        q.pop();
        prev->left = nullptr;
        prev->right = nullptr;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            node->left = nullptr;
            node->right = nullptr;
            prev->right = node;
            prev = node;
        }
    }
};*/

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode *next = curr->left;
                TreeNode *predecessor = next;
                while (predecessor->right != nullptr) predecessor = predecessor->right;
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }
};
