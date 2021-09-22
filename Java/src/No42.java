/*
 * Copyright (c) 9/1/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No42 {
    public int trap(int[] height) {
        int n = height.length;
        int[] leftToRight = new int[n];
        int[] rightToLeft = new int[n];
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                leftToRight[i] = height[0];
                rightToLeft[n - 1 - i] = height[n - 1 - i];
            } else {
                leftToRight[i] = Math.max(leftToRight[i - 1], height[i]);
                rightToLeft[n - 1 - i] = Math.max(rightToLeft[n - i], height[n - i - 1]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (Math.min(rightToLeft[i], leftToRight[i]) - height[i]);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        No42 no42 = new No42();
        System.out.println(no42.trap(height));
    }
}
