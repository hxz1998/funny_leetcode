/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No576 {
    public int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;
        int mod = 1_000_000_007;
        int[][] dp = new int[m][n];
        int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int k = 0; k < N; ++k) {
            int[][] buf = new int[m][n];
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    for (int[] dir : dirs) {
                        if (r + dir[0] < 0 || r + dir[0] >= m || c + dir[1] < 0 || c + dir[1] >= n) buf[r][c]++;
                        else buf[r][c] = (buf[r][c] + dp[r + dir[0]][c + dir[1]]) % mod;
                    }
                }
            }
            dp = buf;
        }
        return dp[i][j];
    }
}
