/**
 * Created by Xiaozhong on 2022/3/20.
 * Copyright (c) 2022/3/20 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
        int n = static_cast<int>(patience.size());
        vector<vector<int>> graph(n);
        for (const vector<int> &v: edges) {
            graph[v[0]].emplace_back(v[1]);
            graph[v[1]].emplace_back(v[0]);
        }
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int ans = 0;
        int dist = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int to = q.front();
                q.pop();
                for (int next: graph[to]) {
                    if (visited[next]) continue;
                    visited[next] = true;
                    q.push(next);
                    int time = patience[next] * ((2 * dist - 1) / patience[next]) + 2 * dist + 1;
                    ans = max(ans, time);
                }
            }
            dist++;
        }
        return ans;
    }
};