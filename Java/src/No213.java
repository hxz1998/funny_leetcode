/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No213 {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return Math.max(rob(nums, 0, n - 1), rob(nums, 1, n));
    }

    private int rob(int[] nums, int start, int end) {
        int[] dp = new int[nums.length + 1];
        dp[start] = 0;
        dp[start + 1] = nums[start];
        for (int i = start + 1; i < end; ++i) {
            dp[i + 1] = Math.max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[end];
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 1};
        No213 no213 = new No213();
        System.out.println(no213.rob(nums));
    }
}
