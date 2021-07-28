/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1060 {
    private int missing(int idx, int[] nums) {
        return nums[idx] - nums[0] - idx;
    }

    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        if (missing(n - 1, nums) < k) return nums[n - 1] + (k - missing(n - 1, nums));
        int idx = 0;
        while (missing(idx, nums) < k) idx++;
        return nums[idx - 1] + k - missing(idx - 1, nums);
    }

    public static void main(String[] args) {
        int[] nums = {4, 7, 9, 10};
        No1060 no1060 = new No1060();
        System.out.println(no1060.missingElement(nums, 3));
        nums = new int[]{1, 2, 4};
        System.out.println(no1060.missingElement(nums, 3));
    }
}
