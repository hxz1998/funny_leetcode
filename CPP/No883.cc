/**
 * Created by Xiaozhong on 2020/12/22.
 * Copyright (c) 2020/12/22 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int row = 0, column = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) ans++;
                row = max(row, grid[i][j]);
                column = max(column, grid[j][i]);
            }
            ans += row + column;
        }
        return ans;
    }
};