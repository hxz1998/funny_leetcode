/*
 * Copyright (c) 8/27/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No45 {
    public int jump(int[] nums) {
        int n = nums.length;
        int maxDistance = 0, ans = 0, end = 0;

        for (int i = 0; i < n - 1; ++i) {
            maxDistance = Math.max(maxDistance, i + nums[i]);
            if (i == end) {
                end = maxDistance;
                ans++;
            }
        }
        return ans;
    }
}
