/*
 * Copyright (c) 7/14/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1818 {
    private static final int MOD = 1_000_000_007;

    public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] rec = new int[n];
        for (int i = 0; i < n; ++i) rec[i] = nums1[i];
        Arrays.sort(rec);
        int ans = 0, max = 0;
        for (int i = 0; i < n; ++i) {
            int diff = Math.abs(nums1[i] - nums2[i]);
            ans += diff;
            ans %= MOD;
            int idx = binarySearch(rec, nums2[i]);
            // 先找左边
            if (idx > 0) max = Math.max(max, diff - (nums2[i] - rec[idx - 1]));
            // 再找右边
            if (idx < n) max = Math.max(max, diff - Math.abs(nums2[i] - rec[idx]));
        }
        return (ans - max + MOD) % MOD;
    }

    private int binarySearch(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        if (nums[right - 1] <= target) return right;
        else if (nums[left] >= target) return left;
        else {
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) right = mid;
                else left = mid + 1;
            }
            return left;
        }
    }
}
