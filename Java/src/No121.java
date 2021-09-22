/*
 * Copyright (c) 8/30/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No121 {
    public int maxProfit(int[] prices) {
        int n = prices.length, min = Integer.MAX_VALUE;
        int[] dp = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            min = Math.min(min, prices[i]);
            dp[i + 1] = Math.max(dp[i], prices[i] - min);
        }
        return dp[n];
    }

    public static void main(String[] args) {
        int[] prices = {7, 6, 4, 3, 1};
        No121 no121 = new No121();
        System.out.println(no121.maxProfit(prices));
    }
}
