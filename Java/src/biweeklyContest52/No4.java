/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest52;

import java.util.Arrays;

public class No4 {
    private static final int MOD = 1_000_000_007;

    public int sumOfFlooredPairs(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            int j = 0;
            while (nums[j] < nums[i]) ++j;
            for (; j < nums.length; ++j) {
                ans += nums[j] / nums[i];
                ans %= MOD;
            }
        }
        return ans % MOD;
    }

    public static void main(String[] args) {
    }
}
