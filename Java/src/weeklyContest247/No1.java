/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest247;

import java.util.Arrays;

public class No1 {
    public int maxProductDifference(int[] nums) {
        Arrays.sort(nums);
        return ((nums[nums.length - 1] * nums[nums.length - 2]) - (nums[0] * nums[1]));
    }
}
