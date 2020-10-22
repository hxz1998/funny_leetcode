/**
 * Created by Xiaozhong on 2020/10/22.
 * Copyright (c) 2020/10/22 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    vector<int> ans;

    void dfs(Node *root) {
        if (!root) return;
        ans.emplace_back(root->val);
        if (!root->children.empty()) {
            for (int i = 0; i < root->children.size(); ++i) {
                dfs(root->children[i]);
            }
        }
    }

public:
    vector<int> preorder(Node *root) {
        dfs(root);
        return ans;
    }
};