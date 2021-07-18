/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest250;

import java.util.Arrays;

public class No2 {
    public int addRungs(int[] rungs, int dist) {
        int n = rungs.length;
        int curr = 0;
        int ans = 0;
        for (int idx = 0; idx < n; ++idx) {
            if (rungs[idx] - curr > dist) {
                ans += (rungs[idx] - curr - 1) / dist;
            }
            curr = rungs[idx];
        }
        return ans;
    }

    public int addRungs2(int[] rungs, int dist) {
        int ans = 0;
        int n = rungs.length;
        long curr = 0;
        for (int idx = 0; idx < n; ) {
            if (rungs[idx] - curr > dist) {
                ++ans;
                curr += dist;
            } else {
                int left = binarySearch(rungs, idx, n - 1, (int) curr);
                curr = rungs[left];
                idx = left + 1;
            }
        }
        return ans;
    }

    private int binarySearch(int[] nums, int left, int right, int target) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, 5, 10};
        No2 no2 = new No2();
        System.out.println(no2.addRungs(nums, 2));
        System.out.println(Long.MAX_VALUE);
        nums = new int[]{3};
        System.out.println(no2.addRungs(nums, 1));
    }
}
