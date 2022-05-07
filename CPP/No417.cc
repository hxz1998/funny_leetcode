/**
 * Created by Xiaozhong on 2022/4/27.
 * Copyright (c) 2022/4/27 Xiaozhong. All rights reserved.
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
    vector<vector<int>> dirs = {{1,  0},
                                {-1, 0},
                                {0,  1},
                                {0,  -1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        vector<vector<int>> ans;
        int n = static_cast<int>(heights.size()), m = static_cast<int>(heights[0].size());
        queue<vector<int>> pacificQueue, atlanticQueue;
        //0 代表 Pacific可以过来， 1 代表 Atlantic可以过来
        vector<vector<vector<bool>>> grid(n, vector<vector<bool>>(m, vector<bool>(2)));
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (x == 0 || y == 0) pacificQueue.push({x, y});
                if (y == m - 1 || x == n - 1) atlanticQueue.push({x, y});
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m));
        while (!pacificQueue.empty()) {
            vector<int> curr = pacificQueue.front();
            int x = curr[0], y = curr[1];
            visited[x][y] = true;
            grid[x][y][0] = true;
            pacificQueue.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]
                    && heights[nx][ny] >= heights[x][y]) {
                    pacificQueue.push({nx, ny});
                }
            }
        }
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        while (!atlanticQueue.empty()) {
            vector<int> curr = atlanticQueue.front();
            atlanticQueue.pop();
            int x = curr[0], y = curr[1];
            visited[x][y] = true;
            grid[x][y][1] = true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]
                    && heights[nx][ny] >= heights[x][y]) {
                    atlanticQueue.push({nx, ny});
                }
            }
        }
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (grid[x][y][0] && grid[x][y][1]) ans.push_back({x, y});
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> heights = {{3, 3, 3, 3, 3, 3},
                                   {3, 0, 3, 3, 0, 3},
                                   {3, 3, 3, 3, 3, 3}};
    Solution s;
    s.pacificAtlantic(heights);
}