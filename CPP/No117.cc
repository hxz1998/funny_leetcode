/**
 * Created by Xiaozhong on 2020/8/5.
 * Copyright (c) 2020/8/5 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "complex_node.h"
#include "queue"

using namespace std;

class Solution {
public:
    Node *connect(Node *root) {
        if (!root) return nullptr;
        queue<Node *> buffer;
        buffer.push(root);
        while (!buffer.empty()) {
            int size = buffer.size();
            for (int i = 0; i < size; i++) {
                Node *node = buffer.front();
                buffer.pop();
                if (i < size - 1) {
                    node->next = buffer.front();
                }
                if (node->left) buffer.push(node->left);
                if (node->right) buffer.push(node->right);
            }
        }
        return root;
    }
};