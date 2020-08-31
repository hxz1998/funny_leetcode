/**
 * Created by Xiaozhong on 2020/8/31.
 * Copyright (c) 2020/8/31 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        // 使用 dp[i][j] 代表答案在区间 [i, j] 所需要的付出的最小代价
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT32_MAX));
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                if (i == j) dp[i][j] = 0;
                else {
                    dp[i][j] = i + dp[i + 1][j];
                    dp[i][j] = min(dp[i][j], j + dp[i][j - 1]);
                    for (int k = i + 1; k < j; k++) {
                        dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                    }
                }
            }
        }
        return dp[1][n];
    }
};