/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */


import java.util.Arrays;

public class No1547 {
    public int minCost(int n, int[] cuts) {
        int m = cuts.length;
        Arrays.sort(cuts);
        int[] newCuts = new int[m + 2];
        for (int i = 1; i <= m; ++i) newCuts[i] = cuts[i - 1];
        newCuts[0] = 0;
        newCuts[m + 1] = n;
        int[][] dp = new int[m + 2][m + 2];
        for (int i = m; i >= 1; --i) {
            for (int j = i; j <= m; ++j) {
                dp[i][j] = i == j ? 0 : Integer.MAX_VALUE;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] += newCuts[j + 1] - newCuts[i - 1];
            }
        }
        return dp[1][m];
    }
}
