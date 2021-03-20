/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No115 {
    public int numDistinct(String s, String t) {
        int n = s.length(), m = t.length();
        if (n < m) return 0;
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) dp[i][m] = 1;
        for (int sIndex = n - 1; sIndex >= 0; --sIndex) {
            for (int tIndex = m - 1; tIndex >= 0; --tIndex) {
                char cs = s.charAt(sIndex);
                char ct = t.charAt(tIndex);
                if (cs == ct) dp[sIndex][tIndex] = dp[sIndex + 1][tIndex] + dp[sIndex + 1][tIndex + 1];
                else dp[sIndex][tIndex] = dp[sIndex + 1][tIndex];
            }
        }
        return dp[0][0];
    }

    public static void main(String[] args) {
        No115 no115 = new No115();
        System.out.println(no115.numDistinct("rabbbit", "rabbit"));
    }
}
