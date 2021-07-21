/*
 * Copyright (c) 7/20/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1877 {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, nums[i] + nums[n -  i - 1]);
        }
        return ans;
    }
}
