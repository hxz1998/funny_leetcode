/*
 * Copyright (c) 7/16/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No918 {
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int max = Integer.MIN_VALUE, curr = 0, min = Integer.MAX_VALUE, sum = 0;
        for (int num : nums) {
            curr = Math.max(num, curr + num);
            max = Math.max(curr, max);
            sum += num;
        }
        if (max < 0) return max;
        curr = 0;
        for (int num : nums) {
            curr = Math.min(num, num + curr);
            min = Math.min(min, curr);
        }
        return Math.max(max, sum - min);
    }

    public static void main(String[] args) {
        int[] nums = {-2, -3, -1};
        No918 no918 = new No918();
        System.out.println(no918.maxSubarraySumCircular(nums));
    }
}

