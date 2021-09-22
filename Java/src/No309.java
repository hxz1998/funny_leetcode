/*
 * Copyright (c) 8/31/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No309 {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n][3];
        /*
        三种状态，
        0， 目前持有股票
        1， 目前不持有股票，而且不处于冷冻期
        2， 目前不持有股票，处于冷冻期
         */
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }
        return Math.max(dp[n - 1][1], dp[n - 1][2]);
    }

    public static void main(String[] args) {
        int[] prices = {1, 2, 3, 0, 2};
        No309 no309 = new No309();
        System.out.println(no309.maxProfit(prices));
    }
}
