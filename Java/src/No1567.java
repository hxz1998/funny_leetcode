/*
 * Copyright (c) 8/30/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1567 {
    public int getMaxLen(int[] nums) {
        int n = nums.length, ans = 0;
        /*
         * dp[i][0] 表示截止到 i - 1 位置时候，乘积为正数的最长长度
         * dp[i][1] 表示截止到 i - 1 位置时候，乘积为负数的最长长度
         */
        int[][] dp = new int[n + 1][2];
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                dp[i + 1][0] = dp[i + 1][1] = 0;
            } else if (nums[i] < 0) {
                dp[i + 1][0] = dp[i][1] == 0 ? 0 : dp[i][1] + 1;
                dp[i + 1][1] = dp[i][0] + 1;
            } else {
                dp[i + 1][0] = dp[i][0] + 1;
                dp[i + 1][1] = dp[i][1] == 0 ? 0 : dp[i][1] + 1;
            }
            ans = Math.max(ans, dp[i + 1][0]);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {0, 1, -2, -3, -4};
        No1567 no1567 = new No1567();
        System.out.println(no1567.getMaxLen(nums));
    }
}
