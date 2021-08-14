/*
 * Copyright (c) 8/10/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No413 {
    public int numberOfArithmeticSlices(int[] nums) {
        int cnt = 0, ans = 0;
        for (int i = 2; i < nums.length; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) ans += ++cnt;
            else cnt = 0;
        }
        return ans;
    }
}
