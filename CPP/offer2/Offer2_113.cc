/**
 * Created by Xiaozhong on 2022/4/7.
 * Copyright (c) 2022/4/7 Xiaozhong. All rights reserved.
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
    // start == 1, 选择了， start == 0, 没选择，start == -1 正在选择
    bool
    dfs(int start, vector<int> &visited, vector<vector<int>> &parents, vector<int> &path) {
        if (visited[start] == 1) return true;
        if (visited[start] == -1) return false;
        visited[start] = -1;
        for (int parent: parents[start]) {
            if (!dfs(parent, visited, parents, path)) return false;
        }
        visited[start] = 1;
        path.push_back(start);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        int n = static_cast<int>(prerequisites.size());
        vector<vector<int>> parents(numCourses, vector<int>());

        for (const vector<int> &preRequest: prerequisites) {
            // [a, b] a 依赖于 b
            parents[preRequest[0]].push_back(preRequest[1]);
        }
        vector<int> visited(numCourses);
        vector<int> path;
        for (int start = 0; start < numCourses; ++start) {
            if (!dfs(start, visited, parents, path)) return {};
        }
        return path;
    }
};

int main() {
    vector<vector<int>> pre = {{1, 0}};
    Solution s;
    s.findOrder(2, pre);
}