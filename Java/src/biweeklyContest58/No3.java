/*
 * Copyright (c) 8/7/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest58;

import java.util.Arrays;

public class No3 {
    public int minSpaceWastedKResizing(int[] nums, int k) {
        int INF = Integer.MAX_VALUE / 2;
        int n = nums.length;
        int[][] dp = new int[n + 1][k + 1];
        for (int i = 0; i <= n; ++i) Arrays.fill(dp[i], INF);
        dp[0][0] = 0;
        int highest = 0, sum = 0;
        for (int idx = 0; idx < n; ++idx) {
            highest = Math.max(highest, nums[idx]);
            sum += nums[idx];
            dp[idx + 1][0] = highest * (idx + 1) - sum;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                int hi = 0, s = 0;
                for (int next = i + 1; next <= n; ++next) {
                    hi = Math.max(hi, nums[next - 1]);
                    s += nums[next - 1];
                    dp[next][j + 1] = Math.min(dp[next][j + 1], dp[i][j] + hi * (next - i) - s);
                }
            }
        }
        return dp[n][k];
    }
}
