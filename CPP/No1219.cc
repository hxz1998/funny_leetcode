/**
 * Created by Xiaozhong on 2022/2/5.
 * Copyright (c) 2022/2/5 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "functional"

using namespace std;

class Solution {
private:
    static constexpr int dirs[4][2] = {{1,  0},
                                       {-1, 0},
                                       {0,  1},
                                       {0,  -1}};
    int ans = 0;
public:
    int getMaximumGold(vector<vector<int>> &grid) {
        function<void(int, int, int)> dfs = [&](int x, int y, int gold) {
            gold += grid[x][y];
            ans = max(ans, gold);
            int rec = grid[x][y];
            grid[x][y] = 0;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] > 0) {
                    dfs(nx, ny, gold);
                }
            }
            grid[x][y] = rec;
        };

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] > 0) dfs(i, j, 0);
            }
        }
        return ans;
    }
};
