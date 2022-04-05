/**
 * Created by Xiaozhong on 2022/4/3.
 * Copyright (c) 2022/4/3 Xiaozhong. All rights reserved.
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

class CBTInserter {
    TreeNode *root;
    queue<TreeNode *> q;
public:
    CBTInserter(TreeNode *_root) : root(_root) {
        q.push(root);
        queue<TreeNode *> aux;
        aux.push(root);
        while (!aux.empty()) {
            int sz = aux.size();
            while (sz--) {
                TreeNode *node = aux.front();
                if (node->left != nullptr) {
                    aux.push(node->left);
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    aux.push(node->right);
                    q.push(node->right);
                }
                aux.pop();
            }
        }
        while (q.front()->left != nullptr && q.front()->right != nullptr) {
            q.pop();
        }
    }

    int insert(int v) {
        TreeNode *front = q.front();
        TreeNode *node = new TreeNode(v);
        if (front->left == nullptr) front->left = node;
        else if (front->right == nullptr) {
            front->right = node;
            q.pop();
        }
        q.push(node);
        return front->val;
    }

    TreeNode *get_root() {
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    CBTInserter in(root);

}