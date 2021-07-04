/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No477 {
    public int totalHammingDistance(int[] nums) {
        int ans = 0, n = nums.length;
        for (int i = 0; i <= 30; ++i) {
            int count = 0;
            for (int num : nums) count += (num >> i) & 1;
            ans += count * (n - count);
        }
        return ans;
    }
}
