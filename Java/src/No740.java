/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No740 {
    public int deleteAndEarn(int[] nums) {
        int maxValue = Arrays.stream(nums).max().getAsInt();
        int[] sums = new int[maxValue + 1];

        for (int num : nums) sums[num] += num;
        return rob(sums);
    }

    private int rob(int[] nums) {
        int n = nums.length;
        int first = nums[0], second = Math.max(nums[1], nums[0]);
        for (int i = 2; i < n; ++i) {
            int tmp = second;
            second = Math.max(first + nums[i], second);
            first = tmp;
        }
        return second;
    }
}
