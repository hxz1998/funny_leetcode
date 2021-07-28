/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No487 {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n = nums.length;
        int left = 0, right = 0, cnt = 0;
        int ans = 0;
        while (right < n) {
            while (right < n && cnt <= 1) {
                if (nums[right] == 0) cnt++;
                right++;
                if (cnt <= 1) ans = Math.max(right - left, ans);
            }

            while (left <= right && cnt > 1) {
                if (nums[left] == 0) cnt--;
                left++;
            }
        }
        return ans;
    }
}
