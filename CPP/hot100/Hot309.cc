/*
 * Created by Xiaozhong on 3/2/2022.
 * Copyright (c) 3/2/2022 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        size_t n = prices.size();
        if (n <= 1) return 0;
        else if (n == 2) return max(prices[1] - prices[0], 0);
        vector<vector<int>> dp(3, vector<int>(n));
        // dp[0]: 手上有股票，所能达到的最大利润
        // dp[1]: 手上没有股票，并且处于冷冻期
        // dp[2]: 手上没有股票，但不处于冷冻期
        dp[0][0] = -prices[0];
        for (size_t day = 1; day < n; ++day) {
            dp[0][day] = max(dp[0][day - 1], dp[2][day - 1] - prices[day]);
            dp[1][day] = dp[0][day - 1] + prices[day];
            dp[2][day] = max(dp[1][day - 1], dp[2][day - 1]);
        }
        return max(dp[1][n - 1], dp[2][n - 1]);
    }
};