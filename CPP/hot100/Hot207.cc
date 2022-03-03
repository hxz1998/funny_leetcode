/*
 * Created by Xiaozhong on 3/3/2022.
 * Copyright (c) 3/3/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
private:
    bool valid = true;

    void dfs(const vector<vector<int>> &edge, vector<int> &visited, int u) {
        visited[u] = 1;
        for (int v: edge[u]) {
            if (visited[u] == 0) {
                dfs(edge, visited, v);
                if (!valid) return;
            } else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> edge(numCourses);
        vector<int> visited(numCourses);
        for (const vector<int> &info: prerequisites) {
            edge[info[1]].push_back(info[0]);
        }
        for (int u = 0; u < numCourses && valid; ++u) {
            if (visited[u] == 0) dfs(edge, visited, u);
        }
        return valid;
    }
};