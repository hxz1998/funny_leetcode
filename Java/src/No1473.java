/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1473 {
    private static final int INFTY = Integer.MAX_VALUE / 2;

    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        for (int i = 0; i < houses.length; ++i) houses[i]--;

        // [0, i] 的房子涂上颜色，最末尾的 i 颜色为 j，属于第 k 个街区所需要的最少花费
        int[][][] dp = new int[m][n][target];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) Arrays.fill(dp[i][j], INFTY);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 已经涂上了颜色，但是颜色不对
                if (houses[i] != -1 && houses[i] != j) continue;

                for (int k = 0; k < target; ++k) {
                    for (int j0 = 0; j0 < n; ++j0) {
                        if (j == j0) {
                            if (i == 0) {
                                if (k == 0) dp[i][j][k] = 0;
                            } else dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][j][k]);
                        } else if (i > 0 && k > 0) {
                            dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][j0][k - 1]);
                        }
                    }
                    if (dp[i][j][k] != INFTY && houses[i] == -1) dp[i][j][k] += cost[i][j];
                }
            }
        }
        int ans = INFTY;
        for (int j = 0; j < n; ++j) ans = Math.min(ans, dp[m - 1][j][target - 1]);
        return ans == INFTY ? -1 : ans;
    }
}
