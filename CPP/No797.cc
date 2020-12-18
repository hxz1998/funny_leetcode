/**
 * Created by Xiaozhong on 2020/12/18.
 * Copyright (c) 2020/12/18 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    void dfs(const vector<vector<int>> &graph, int start, int target, vector<vector<int>> &ans, vector<int> &buf) {
        // 找到一个没有后继节点的节点，那么就直接返回
        if (graph[start].empty()) return;
        // 在路径缓冲区中加入当前遍历的节点
        buf.push_back(start);
        // 对当前节点可达的后继节点挨个递归
        for (int idx : graph[start]) {
            if (idx == target) {
                // 如果找到了目标节点，那么就放到返回值中去
                buf.push_back(idx);
                ans.emplace_back(buf);
                buf.pop_back();
            } else {
                // 否则就递归搜索
                dfs(graph, idx, target, ans, buf);
            }
        }
        // 回溯，把当前节点弹出来
        buf.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> ans;
        vector<int> buf;
        dfs(graph, 0, graph.size() - 1, ans, buf);
        return ans;
    }
};