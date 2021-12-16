/*
 * Created by Xiaozhong on 12/13/2021.
 * Copyright (c) 12/13/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr) return root;
        covert(root);
        head->left = prev;
        prev->right = head;
        return head;
    }

private:
    Node *prev, *head;

    void covert(Node *curr) {
        if (curr == nullptr) return;
        covert(curr->left);
        if (prev != nullptr) prev->right = curr;
        else head = curr;
        curr->left = prev;
        prev = curr;
        covert(curr->right);
    }
};