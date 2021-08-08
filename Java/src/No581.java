/*
 * Copyright (c) 8/3/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No581 {
    public int findUnsortedSubarray(int[] nums) {
        int n = nums.length, left = 0, right = n - 1;
        int[] copy = new int[n];
        System.arraycopy(nums, 0, copy, 0, n);
        Arrays.sort(nums);
        while (left < n && nums[left] == copy[left]) left++;
        while (right > 0 && nums[right] == copy[right]) right--;
        return Math.max(right - left + 1, 0);
    }
}
