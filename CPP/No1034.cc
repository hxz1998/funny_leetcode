/*
 * Created by Xiaozhong on 12/7/2021.
 * Copyright (c) 12/7/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
private:
    int dirs[4][2] = {{1,  0},
                      {-1, 0},
                      {0,  1},
                      {0,  -1}};
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color) {
        int n = grid.size(), m = grid[0].size();
        int src = grid[row][col];
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> pairs;
        if (row == 0 || row == n - 1 || col == 0 || col == m - 1 ||
            grid[row][col] != grid[row + 1][col] && grid[row][col] != grid[row - 1][col] &&
            grid[row][col - 1] != grid[row][col] && grid[row][col + 1] != grid[row][col])
            pairs.emplace_back(make_pair(row, col));
        dfs(grid, visited, row, col, n, m, src, pairs);
        for (auto[x, y]: pairs) {
            grid[x][y] = color;
        }
        return grid;
    }

private:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited,
             int x, int y,
             int n, int m,
             int src,
             vector<pair<int, int>> &pairs) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx < n && nx >= 0 && ny < m && ny >= 0 && !visited[nx][ny] && grid[nx][ny] == src) {
                if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1 ||
                    grid[nx + 1][ny] != src || grid[nx - 1][ny] != src ||
                    grid[nx][ny + 1] != src || grid[nx][ny - 1] != src) {
                    pairs.emplace_back(make_pair(nx, ny));
                }
                visited[nx][ny] = true;
                dfs(grid, visited, nx, ny, n, m, src, pairs);
            }
        }
    }
};