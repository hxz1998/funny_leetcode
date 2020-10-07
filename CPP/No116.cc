/**
 * Created by Xiaozhong on 2020/8/5.
 * Copyright (c) 2020/8/5 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "complex_node.h"

using namespace std;

class Solution {
private:
    void dfs(Node *root, Node *next) {
        if (root) {
            root->next = next;
            dfs(root->left, root->right);
            dfs(root->right, root->next != nullptr ? root->next->left : nullptr);
        }
    }
public:
    Node *connect(Node *root) {
        dfs(root, nullptr);
        return root;
    }
};