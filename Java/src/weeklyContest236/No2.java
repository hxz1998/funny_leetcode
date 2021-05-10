/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest236;

public class No2 {
    public int minSideJumps(int[] obstacles) {
        int n = obstacles.length;
        int[][] dp = new int[n + 1][3];
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 1;
        for (int i = 1; i <= n; ++i) {
            // 对于赛道 1， 那么只可以来自前面或者下面
            dp[i][0] = obstacles[i] == 1 ? Integer.MAX_VALUE : min(dp[i - 1][0] + 1, obstacles[i] == 2 ? Integer.MAX_VALUE : dp[i - 1][1] + 2);
            dp[i][1] = obstacles[i] == 2 ? Integer.MAX_VALUE : min(dp[i - 1][1] + 1,
                    min(obstacles[i] == 1 ? Integer.MAX_VALUE : dp[i - 1][0] + 2, obstacles[i] == 3 ? Integer.MAX_VALUE : dp[i - 1][2] + 2));
            dp[i][2] = obstacles[i] == 3 ? Integer.MAX_VALUE : min(dp[i - 1][2] + 1, obstacles[i] == 1 ? Integer.MAX_VALUE : dp[i - 1][1] + 2);
        }
        return min(dp[n][0], min(dp[n][1], dp[n][2]));
    }

    private int min(int a, int b) {
        return Math.min(a, b);
    }

    public static void main(String[] args) {
        No2 no2 = new No2();
        int[] obstacles = {0, 1, 2, 3, 0};
        System.out.println(no2.minSideJumps(obstacles));
    }
}
