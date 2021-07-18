/*
 * Copyright (c) 7/16/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No918 {
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int[] numsCopy = new int[n * 2];
        for (int i = 0; i < n; ++i) {
            numsCopy[i] = nums[i];
            numsCopy[i + n] = nums[i];
        }
        return reduce(numsCopy);
    }

    private int reduce(int[] nums) {
        int n = nums.length - 1;
        int[] dp = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = Math.max(dp[i] + nums[i], nums[i]);
        }
        return Arrays.stream(dp).max().getAsInt();
    }
}

