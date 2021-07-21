/*
 * Copyright (c) 7/19/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1838 {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 1;
        int n = nums.length;
        long total = 0;
        for (int left = 0, right = 1; right < n; ++right) {
            total += (long) (nums[right] - nums[right - 1]) * (right - left);
            while (total > k) {
                total -= (nums[right] - nums[left]);
                left++;
            }
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }
}
