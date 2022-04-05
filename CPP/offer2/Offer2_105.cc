/**
 * Created by Xiaozhong on 2022/4/2.
 * Copyright (c) 2022/4/2 Xiaozhong. All rights reserved.
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
    vector<vector<int>> dirs = {{-1, 0},
                                {1,  0},
                                {0,  -1},
                                {0,  1}};

    int bfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
        int ret = 0;
        queue<vector<int>> q;
        q.push({x, y});
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                ret++;
                vector<int> prev = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nx = prev[0] + dirs[j][0];
                    int ny = prev[1] + dirs[j][1];
                    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.front().size() &&
                        grid[nx][ny] == 1 && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return ret;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int n = static_cast<int>(grid.size()), m = static_cast<int>(grid.front().size());
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m));
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (!visited[x][y] && grid[x][y] == 1) {
                    visited[x][y] = true;
                    ans = max(ans, bfs(grid, visited, x, y));
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {{0, 1, 1},
                                {1, 1, 0}};
    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;
}