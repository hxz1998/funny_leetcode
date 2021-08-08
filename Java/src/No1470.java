/*
 * Copyright (c) 8/5/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1470 {
    public int[] shuffle(int[] nums, int n) {
        int size = nums.length, left = 0, right = n;
        int[] ans = new int[size];
        for (int idx = 0; idx < size; ++idx) {
            if (idx % 2 == 0) ans[idx] = nums[left++];
            else ans[idx] = nums[right++];
        }
        return ans;
    }
}
