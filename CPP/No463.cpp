/**
 * Created by Xiaozhong on 2020/9/28.
 * Copyright (c) 2020/9/28 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), perimeter = 0;
        vector<vector<int>> ext_grid(n + 2, vector<int>(m + 2, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ext_grid[i + 1][j + 1] = grid[i][j];
            }
        }
        /**
         * 对 i, j 点进行检查，每多一个方向是 0 ，那么边数就 + 1
         */
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (ext_grid[i][j] == 1) {
                    if (ext_grid[i - 1][j] == 0) ++perimeter;
                    if (ext_grid[i + 1][j] == 0) ++perimeter;
                    if (ext_grid[i][j - 1] == 0) ++perimeter;
                    if (ext_grid[i][j + 1] == 0) ++perimeter;
                }
            }
        }
        return perimeter;
    }
};

int main() {
    vector<vector<int>> grids = {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0}
    };
    Solution s;
    cout << s.islandPerimeter(grids);
}