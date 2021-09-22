/*
 * Copyright (c) 9/15/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No162 {
    private int helper(int[] nums, int left, int right) {
        if (left == right) return left;
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) return helper(nums, left, mid);
        return helper(nums, mid + 1, right);
    }

    public int findPeakElement(int[] nums) {
        return helper(nums, 0, nums.length - 1);
    }
}
