/*
 * Copyright (c) 8/5/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1262 {

    public int maxSumDivThree(int[] nums) {
        int n = nums.length;
        int[] dp = new int[3];
        for (int i = 0; i < n; ++i) {
            int a = dp[0] + nums[i], b = dp[1] + nums[i], c = dp[2] + nums[i];
            dp[a % 3] = Math.max(dp[a % 3], a);
            dp[b % 3] = Math.max(dp[b % 3], b);
            dp[c % 3] = Math.max(dp[c % 3], c);
        }
        return dp[0];
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 4};
        No1262 no1262 = new No1262();
        System.out.println(no1262.maxSumDivThree(nums));
    }
}
