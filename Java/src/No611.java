/*
 * Copyright (c) 8/4/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No611 {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int ans = 0;
        for (int idx = n - 1; idx >= 2; --idx) {
            int left = 0, right = idx - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[idx]) {
                    ans += right - left;
                    right--;
                } else left++;
            }
        }
        return ans;
    }
}
