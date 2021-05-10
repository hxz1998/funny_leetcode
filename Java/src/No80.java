/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No80 {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        if (n <= 2) return n;
        // left 用来放，right 用来读
        int left = 2, right = 2;
        while (right < n) {
            if (nums[left - 2] != nums[right]) nums[left++] = nums[right];
            ++right;
        }
        return left;
    }

    public static void main(String[] args) {
        int[] nums = {1, 1, 1, 2, 2, 3};
        No80 no80 = new No80();
        int ret = no80.removeDuplicates(nums);
        for (int i = 0; i < ret; ++i) System.out.print(nums[i] + " ");
    }
}
