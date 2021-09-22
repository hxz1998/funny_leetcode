/*
 * Copyright (c) 8/18/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No552 {
    private static final int MOD = 1_000_000_007;

    public int checkRecord(int n) {

        int[][][] dp = new int[n + 1][2][3];
        for (int i = 1; i <= n; ++i) {
            // 以 P 结尾
            for (int j = 0; j <= 1; ++j) {
                for (int k = 0; k <= 2; ++k) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }
            // 以 A 结尾
            for (int k = 0; k <= 2; ++k) {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }
            // 以 L 结尾
            for (int j = 0; j <= 1; ++j) {
                for (int k = 1; k <= 2; ++k) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
        }
        int sum = 0;
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 2; ++k) {
                sum = (sum + dp[n][j][k]) % MOD;
            }
        }
        return sum;
    }
}
