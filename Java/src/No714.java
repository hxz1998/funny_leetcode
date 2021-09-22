/*
 * Copyright (c) 8/31/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No714 {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int[][] dp = new int[n][2];
        /*
        两个状态：
        0， 持有股票
        1， 不持有股票
         */
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[n - 1][1];
    }

    public static void main(String[] args) {
        No714 no714 = new No714();
        int[] prices = {1, 3, 2, 8, 4, 9};
        System.out.println(no714.maxProfit(prices, 2));
    }
}
