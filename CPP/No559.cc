/**
 * Created by Xiaozhong on 2020/10/18.
 * Copyright (c) 2020/10/18 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

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
private:
    int max_depth = 0, depth = 0;

    // 深度优先搜索 + 回溯算法
    void dfs(Node *root) {
        if (!root) return;
        ++depth;    // 把当前节点带来的深度增益加上
        max_depth = max(depth, max_depth);
        for (auto node :root->children) {   // 挨个遍历它的孩子们
            dfs(node);
        }
        --depth;    // 回溯，把这个节点带来的增益去掉
    }

public:
    int maxDepth(Node *root) {
        dfs(root);
        return max_depth;
    }
};