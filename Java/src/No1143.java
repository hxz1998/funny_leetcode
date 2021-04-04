/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1143 {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 如果 t1[i] == t2[j] 那么就可以从 dp[i - 1][j - 1] 转移过来，加上 1 就好了
                if (text1.charAt(i) == text2.charAt(j)) dp[i + 1][j + 1] = dp[i][j] + 1;
                // 否则的话，就看看从哪个方向过来能得到最大值
                else dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args) {
        No1143 no1143 = new No1143();
        System.out.println(no1143.longestCommonSubsequence("abcde", "ace"));
    }
}
