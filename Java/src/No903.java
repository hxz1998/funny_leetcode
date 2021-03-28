/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No903 {
    public int numPermsDISequence(String S) {
        int MOD = 1_000_000_007;
        int n = S.length();
        int[][] dp = new int[n + 1][n + 1];
        Arrays.fill(dp[0], 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (S.charAt(i - 1) == 'D') {
                    for (int k = j; k < i; ++k) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= MOD;
                    }
                } else {
                    for (int k = 0; k < j; ++k) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int x : dp[n]) {
            ans += x;
            ans %= MOD;
        }
        return ans;
    }
}
