/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package offer;

public class No42 {
    private final int BOUNDARY = Integer.MIN_VALUE;

    public int maxSubArray(int[] nums) {
        return sum(nums, 0, nums.length - 1);
    }

    private int sum(int[] nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + (right - left) / 2;
        int leftSum = sum(nums, left, mid);
        int rightSum = sum(nums, mid + 1, right);
        int totalSum = helper(nums, left, right, mid);
        return Math.max(totalSum, Math.max(leftSum, rightSum));
    }

    private int helper(int[] nums, int left, int right, int mid) {
        if (left == right) return nums[left];
        int sum = 0, leftSum = Integer.MIN_VALUE;
        for (int i = mid; i >= left; --i) {
            sum += nums[i];
            leftSum = Math.max(leftSum, sum);
        }
        sum = 0;
        int rightSum = Integer.MIN_VALUE;
        for (int i = mid + 1; i <= right; ++i) {
            sum += nums[i];
            rightSum = Math.max(rightSum, sum);
        }
        return leftSum + rightSum;
    }

    public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        No42 no42 = new No42();
        System.out.println(no42.maxSubArray(nums));
    }
}
