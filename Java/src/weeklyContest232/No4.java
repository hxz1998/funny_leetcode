/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest232;

import java.util.ArrayList;

public class No4 {
    public int maximumScore(int[] nums, int k) {
        int left = k, right = k, size = nums.length, ans = 0;
        while (true) {
            while (left >= 0 && nums[left] >= nums[k]) left--;
            while (right < size && nums[right] >= nums[k]) right++;
            ans = Math.max(ans, (right - left - 1) * nums[k]);
            if (left < 0 && right == size) break;
            if (left >= 0 && right < size) nums[k] = Math.max(nums[left], nums[right]);
            else if (left < 0) nums[k] = nums[right];
            else nums[k] = nums[left];
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1, 4, 3, 7, 4, 5};
        No4 no4 = new No4();
        nums = new int[]{5, 5, 4, 5, 4, 1, 1, 1};
        nums = new int[]{8182, 1273, 9847, 6230, 52, 1467, 6062, 726, 4852, 4507, 2460, 2041, 500, 1025, 5524};
        System.out.println(no4.maximumScore(nums, 8));
    }
}
