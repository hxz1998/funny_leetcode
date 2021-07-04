/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No421 {
    public int findMaximumXOR(int[] nums) {
        int ans = 0;
        for (int left = 0; left < nums.length; ++left) {
            for (int right = left + 1; right < nums.length; ++right) {
                ans = Math.max(nums[left] ^ nums[right], ans);
            }
        }
        return ans;
    }
}
