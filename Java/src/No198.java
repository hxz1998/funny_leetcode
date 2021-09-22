/*
 * Copyright (c) 8/27/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No198 {
    public int rob(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n + 1][2];
        // 0 是指偷窃 i 位置处的屋子，1 是指不偷窃 i 位置处的屋子
        dp[1][0] = nums[0];
        dp[1][1] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i + 1][0] = Math.max(dp[i - 1][0] + nums[i], dp[i][1] + nums[i]);
            dp[i + 1][1] = Math.max(dp[i][0], dp[i][1]);
        }
        return Math.max(dp[n][0], dp[n][1]);
    }

    public static void main(String[] args) {
        int[] nums = {2, 7, 9, 3, 1};
        No198 no198 = new No198();
        System.out.println(no198.rob(nums));
    }
}
