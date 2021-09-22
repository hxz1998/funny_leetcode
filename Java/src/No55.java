/*
 * Copyright (c) 8/27/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No55 {
    public boolean canJump(int[] nums) {
        int maxDistance = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i <= maxDistance) {
                maxDistance = Math.max(nums[i] + i, maxDistance);
                if (maxDistance >= nums.length - 1) return true;
            }
        }
        return false;
    }
}
