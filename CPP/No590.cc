/**
 * Created by Xiaozhong on 2020/10/23.
 * Copyright (c) 2020/10/23 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

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
        // 先遍历
        if (!root->children.empty()) {
            for (int i = 0; i < root->children.size(); ++i) {
                dfs(root->children[i]);
            }
        }
        // 后访问
        ans.emplace_back(root->val);
    }

public:
    vector<int> postorder(Node *root) {
        dfs(root);
        return ans;
    }
};