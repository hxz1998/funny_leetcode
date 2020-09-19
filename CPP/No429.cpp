/**
 * Created by Xiaozhong on 2020/9/19.
 * Copyright (c) 2020/9/19 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

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
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> layer;
            int size = q.size();    // 记录当前层的元素个数
            for (int i = 0; i < size; ++i) {
                Node *curr = q.front(); // 取出来当前层的元素
                q.pop();
                for (Node *item : curr->children) {
                    q.push(item);
                }
                layer.push_back(curr->val);
            }
            ans.push_back(layer);
        }
        return ans;
    }
};