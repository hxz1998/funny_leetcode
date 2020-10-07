/**
 * Created by Xiaozhong on 2020/8/12.
 * Copyright (c) 2020/8/12 Xiaozhong. All rights reserved.
 */

#include "simple_node.h"
#include "map"
#include "queue"

using namespace std;

class Solution {
public:
    Node *cloneGraph(Node *node) {
        return dfs(node);
    }

private:
    map<Node *, Node *> visited;

    Node *dfs(Node *root) {
        if (!root) return nullptr;
        if (visited.count(root)) return visited[root];
        vector<Node *> neighbors;
        Node *clone = new Node(root->val, neighbors);
        visited[root] = clone;
        for (Node *node : root->neighbors) clone->neighbors.push_back(dfs(node));
        return clone;
    }
};

