/**
 * Created by Xiaozhong on 2020/10/23.
 * Copyright (c) 2020/10/23 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include "queue"
#include "stack"
#include "unordered_set"

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

// 递归方法
/*
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
};*/


// 迭代方法
/*
class Solution {
public:
    vector<int> postorder(Node *root) {
        deque<pair<int, Node *>> dq;
        vector<int> ans;
        dq.push_back({0, root});
        while (!dq.empty()) {
            auto item = dq.back();
            dq.pop_back();
            int cnt = item.first;
            Node *node = item.second;
            if (node == nullptr) continue;
            else if (cnt == node->children.size()) ans.emplace_back(node->val);
            else if (cnt < node->children.size()) {
                dq.push_back({cnt + 1, node});
                dq.push_back({0, node->children[cnt]});
            }
        }
        return ans;
    }
};*/

// 另一种迭代方法
class Solution {
public:
    vector<int> postorder(Node *root) {
        vector<int> ans;
        if (nullptr == root) return ans;

        stack<Node *> stk;
        unordered_set<Node *> visited;
        stk.push(root);
        while (!stk.empty()) {
            Node *node = stk.top();
            if (node->children.empty() || visited.find(node) != visited.end()) {
                stk.pop();
                ans.emplace_back(node->val);
                continue;
            }
            // 从右往左添加子节点
            for (vector<Node *>::reverse_iterator iter = node->children.rbegin();
                 iter != node->children.rend();
                 ++iter) {
                stk.push(*iter);
            }
            // 记录当前节点已经访问完了，不需要再访问了
            visited.insert(node);
        }
        return ans;
    }
};