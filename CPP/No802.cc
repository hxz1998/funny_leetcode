/**
 * Created by Xiaozhong on 2020/12/23.
 * Copyright (c) 2020/12/23 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> color(n);
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (dfs(i, color, graph)) {
            ans.push_back(i);
        }
        return ans;

    }

private:
    // black: 2, gray: 1, white: 0
    bool dfs(int node, vector<int> &color, vector<vector<int>> &graph) {
        if (color[node] > 0) return color[node] == 2;
        color[node] = 1;
        for (int neighboor : graph[node]) {
            if (color[node] == 2) continue;
            if (color[neighboor] == 1 || !dfs(neighboor, color, graph)) return false;
        }
        color[node] = 2;
        return true;
    }
};