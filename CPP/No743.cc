/**
 * Created by Xiaozhong on 2020/12/2.
 * Copyright (c) 2020/12/2 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (const vector<int> &edge : times) {
            graph[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
        }
        unordered_map<int, int> dist;
        for (int node = 1; node <= N; ++node) dist[node] = INT32_MAX;
        dist[K] = 0;
        vector<int> seen(N + 1, 0);
        while (true) {
            int candNode = -1;
            int candDist = INT32_MAX;
            for (int i = 1; i <= N; ++i) {
                if (!seen[i] && dist[i] < candDist) {
                    candDist = dist[i];
                    candNode = i;
                }
            }
            if (candNode < 0) break;
            seen[candNode] = true;
            if (graph.count(candNode)) {
                for (pair<int, int> &info : graph[candNode]) {
                    dist[info.first] = min(dist[info.first], dist[candNode] + info.second);
                }
            }
        }
        int ans = 0;
        for (auto iter = dist.begin(); iter != dist.end(); ++iter) {
            if (iter->second == INT32_MAX) return -1;
            ans = max(ans, iter->second);
        }
        return ans;
    }
};