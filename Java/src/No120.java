/*
 * Copyright (c) 9/11/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.List;

public class No120 {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[][] dp = new int[n][n];
        dp[0][0] = triangle.get(0).get(0);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) dp[i][j] = triangle.get(i).get(j) + dp[i - 1][j];
                else if (j == i) dp[i][j] = triangle.get(i).get(j) + dp[i - 1][j - 1];
                else dp[i][j] = Math.min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle.get(i).get(j);
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) ans = Math.min(ans, dp[n - 1][i]);
        return ans;
    }
}
