/**
 * Created by Xiaozhong on 2020/8/27.
 * Copyright (c) 2020/8/27 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "unordered_map"
#include "queue"

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};
        vector<int> ans;
        vector<int> degree(n, 0);       // 用来记录每一个节点的度
        unordered_map<int, vector<int>> mapper(n);  // 将每一个节点对应的边记录下来
        for (vector<int> edge : edges) {
            degree[edge[0]]++;                  // 计算 edge[0] 节点的度
            degree[edge[1]]++;                  // 计算 edge[1] 节点的度
            mapper[edge[0]].push_back(edge[1]); // 把与 edge[0] 相连接的边添加进来
            mapper[edge[1]].push_back(edge[0]); // 把与 edge[1] 相连接的边添加进来
        }

        // 创建队列，并且把度为 1 的节点（叶子节点）添加进队列中
        queue<int> q;
        for (int i = 0; i < n; i++) if (degree[i] == 1) q.push(i);

        while (!q.empty()) {
            vector<int> res;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                vector<int> next_set = mapper[cur];
                for (int next : next_set) {
                    degree[next]--; // 删除叶子节点后，要将与其相邻的节点的度数减少
                    if (degree[next] == 1) q.push(next);
                }
            }
            ans = res;
        }
        return ans;
    }
};