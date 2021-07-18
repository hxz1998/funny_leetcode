/*
 * Copyright (c) 7/16/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.regex.Pattern;

public class No152 {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        // 第一行记录正数的最大值
        // 第二行记录负数的最小值
        int[][] dp = new int[n + 1][2];
        for (int i = 0; i <= n; ++i) Arrays.fill(dp[i], 1);
        dp[0][1] = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                dp[i + 1][0] = dp[i][1] == 0 ? 0 : dp[i][1] * nums[i];
                dp[i + 1][1] = dp[i][0] == 0 ? nums[i] : dp[i][0] * nums[i];
            } else if (nums[i] > 0) {
                dp[i + 1][0] = dp[i][0] == 0 ? nums[i] : dp[i][0] * nums[i];
                dp[i + 1][1] = dp[i][1] == 0 ? 0 : dp[i][1] * nums[i];
            } else {
                dp[i + 1][0] = 0;
                dp[i + 1][1] = 0;
            }
        }
        int ans = Integer.MIN_VALUE;
        for (int i = 1; i <= n; ++i) {
            ans = Math.max(dp[i][0], ans);
        }
        return Math.max(ans, 0);
    }

    public static void main(String[] args) {
        No152 no152 = new No152();
        int[] nums = {2, 3, -2, 4};
        System.out.println(no152.maxProduct(nums));
        nums = new int[]{-2, 0, -1};
        System.out.println(no152.maxProduct(nums));
        nums = new int[]{3, -1, 4};
        System.out.println(no152.maxProduct(nums));
    }
}
