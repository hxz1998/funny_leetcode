/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (x == 0 && y == 0) continue;
                else if (x == 0) grid[x][y] = grid[x][y - 1] + grid[x][y];
                else if (y == 0) grid[x][y] = grid[x - 1][y] + grid[x][y];
                else grid[x][y] = min(grid[x - 1][y], grid[x][y - 1]) + grid[x][y];
            }
        }
        return grid[m - 1][n - 1];
    }
};