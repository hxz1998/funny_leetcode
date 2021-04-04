/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No17dot16 {
    public int massage(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        // 二维存储，[i][0] 表示第 i 个不接，[i][1] 表示第 i 个接
        int[][] dp = new int[n][2];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            // 如果第 i 位不接，那么前面的就都可以，找到一个最大的就好了
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
            // 如果第 i 位接，那么久需要保证第 i - 1 是接的
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return Math.max(dp[n - 1][0], dp[n - 1][1]);
    }

    public static void main(String[] args) {
        int[] nums = {2, 1, 1, 2};
        No17dot16 no17dot16 = new No17dot16();
        System.out.println(no17dot16.massage(nums));
    }
}
