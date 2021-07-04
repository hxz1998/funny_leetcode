/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No238 {
    /*public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] right = new int[n], left = new int[n];
        left[0] = 1;
        for (int i = 1; i < n; ++i) left[i] = left[i - 1] * nums[i - 1];
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) right[i] = right[i + 1] * nums[i + 1];
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) ans[i] = left[i] * right[i];
        return ans;
    }*/

    // 上面的方法不是很好，这里有一个空间复杂度为 1，时间复杂度为 n 的方法
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        ans[0] = 1;
        for (int i = 1; i < n; ++i) ans[i] = ans[i - 1] * nums[i - 1];
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = ans[i] * right;
            right = right * nums[i];
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4};
        No238 no238 = new No238();
        System.out.println(Arrays.toString(no238.productExceptSelf(nums)));
    }
}
