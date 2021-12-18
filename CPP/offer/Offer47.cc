/**
 * Created by Xiaozhong on 2021/12/16.
 * Copyright (c) 2021/12/16 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if (j == 0) {
                    // 走到了第一列，只能从上面来
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                } else if (i == 0) {
                    // 在第一行进行处理，只能从左边来
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};