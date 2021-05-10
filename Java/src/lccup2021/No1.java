/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lccup2021;

import java.util.Arrays;

public class No1 {
    public int purchasePlans(int[] nums, int target) {
        int mod = 1_000_000_007;
        int ans = 0;
        // 首先对整体进行排序
        Arrays.sort(nums);
        // 双指针，left 从前往后找，right 从后往前
        int left = 0, right = nums.length - 1;
        while (left < right) {
            // 如果当前左右之和大于了目标值，说明偏大了，就把右指针往左移动
            if (nums[left] + nums[right] > target) right--;
            else {
                // 否则的话，说明找到了合适的，需要把两者中间的元素个数都累加起来
                ans += right - left;
                // 然后再向右移动左指针
                left++;
            }
            ans %= mod;
        }
        return ans % mod;
    }

    // 二分查找最后一个小于等于 target 的位置
    private int binarySearch(int[] nums, int target) {
        int left = 0, right = nums.length;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else if (nums[mid] < target) left = mid + 1;
            else break;
        }
        while (mid < right && nums[mid] <= target) ++mid;
        return mid - 1;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 6};
        No1 no1 = new No1();
        System.out.println(no1.binarySearch(nums, 5));
    }
}
