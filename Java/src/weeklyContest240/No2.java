/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest240;

public class No2 {
    public int maxDistance(int[] nums1, int[] nums2) {
        int ans = 0, idx1 = 0, idx2 = 0;
        while (idx1 < nums1.length && idx2 < nums2.length) {
            if (nums1[idx1] > nums2[idx2]) idx1++;
            else {
                ans = Math.max(ans, idx2 - idx1);
                idx2++;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums1 = {2, 2, 2};
        int[] nums2 = {10, 10, 1};
        No2 no2 = new No2();
        System.out.println(no2.maxDistance(nums1, nums2));
    }
}

