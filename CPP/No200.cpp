/**
 * Created by Xiaozhong on 2020/8/20.
 * Copyright (c) 2020/8/20 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == '0') return;
        grid[i][j] = '0';           // 访问过的下标要置为 0，防止重复检查
        dfs(grid, i + 1, j);    // 上下左右挨个递归检查
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        int count = 0;
        // 整个二维数组挨个遍历
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {    // 当找到一个岛屿的时候，对其四周进行检查同时计数
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};