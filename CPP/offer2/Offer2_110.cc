/**
 * Created by Xiaozhong on 2022/5/5.
 * Copyright (c) 2022/5/5 Xiaozhong. All rights reserved.
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
#include <list>
#include <random>

using namespace std;

class Solution {
private:
    void backtrack(const vector<vector<int>> &graph, vector<bool> &visited,
                   vector<int> &path, vector<vector<int>> &ans, int pos, const int target) {
        if (pos == target) {
            ans.push_back(path);
            return;
        }
        for (int next: graph[pos]) {
            if (visited[next]) continue;
            visited[next] = true;
            path.push_back(next);
            backtrack(graph, visited, path, ans, next, target);
            path.pop_back();
            visited[next] = false;
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        int n = static_cast<int>(graph.size());
        vector<bool> visited(n);
        vector<int> path;
        vector<vector<int>> ans;
        backtrack(graph, visited, path, ans, 0, n - 1);
        return ans;
    }
};