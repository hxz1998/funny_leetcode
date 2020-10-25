/**
 * Created by Xiaozhong on 2020/7/22.
 * Copyright (c) 2020/7/22 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) dp[i][j] = grid[i][j];    // 左上角
                else if (i == 0) dp[i][j] = dp[i][j - 1] + grid[i][j];  // 第一行
                else if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];  // 第一列
                else dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];   // 其他一般情况
            }
        }
        return dp.back().back();
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    assert(s.minPathSum(grid) == 7);
}