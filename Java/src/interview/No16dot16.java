/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No16dot16 {
    public int[] subSort(int[] array) {
        int[] ans = {-1, -1};
        int n = array.length;
        if (n > 0) {
            int currMin = Integer.MAX_VALUE;
            for (int idx = n - 1; idx >= 0; --idx) {
                if (array[idx] > currMin) {
                    ans[0] = idx;
                }
                currMin = Math.min(currMin, array[idx]);
            }
            int currMax = Integer.MIN_VALUE;
            for (int idx = 0; idx < n; ++idx) {
                if (array[idx] < currMax) {
                    ans[1] = idx;
                }
                currMax = Math.max(currMax, array[idx]);
            }
        }
        return ans;
    }
}
