/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1269 {
    private static final int MOD = 1_000_000_007;

    public int numWays(int steps, int arrLen) {
        int maxColumn = Math.min(arrLen, steps + 1);
        int[][] dp = new int[steps + 1][maxColumn];
        dp[0][0] = 1;
        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j < maxColumn; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j + 1 < maxColumn) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
        return dp[steps][0];
    }
}
