/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = {{1,  0},
                                {-1, 0},
                                {0,  -1},
                                {0,  1}};

    void dfs(vector<vector<char>> &grid, int x, int y) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                dfs(grid, nx, ny);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == '1') {
                    dfs(grid, x, y);
                    count++;
                }
            }
        }
        return count;
    }
};