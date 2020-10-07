/**
 * Created by Xiaozhong on 2020/8/21.
 * Copyright (c) 2020/8/21 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool is_valid = true;
    vector<int> ans;

    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (!visited[v]) {
                dfs(v);
                if (!is_valid) return;
            }
            if (visited[v] == 1) {
                is_valid = false;
                return;
            }
        }
        visited[u] = 2;
        ans.push_back(u);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (vector<int> item : prerequisites) edges[item[1]].push_back(item[0]);
        for (int i = 0; i < numCourses && is_valid; i++) if (!visited[i]) dfs(i);

        if (!is_valid) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};