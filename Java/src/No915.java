/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No915 {
    public int partitionDisjoint(int[] arr) {
        int n = arr.length;
        int[] leftMax = new int[n];
        int[] rightMin = new int[n];
        leftMax[0] = arr[0];
        rightMin[n - 1] = arr[n - 1];
        for (int i = 1; i < n; ++i) leftMax[i] = Math.max(leftMax[i - 1], arr[i]);
        for (int i = n - 2; i >= 0; --i) rightMin[i] = Math.min(rightMin[i + 1], arr[i]);

        for (int i = 0; i < n - 1; ++i) {
            if (leftMax[i] < rightMin[i + 1]) return i + 1;
        }
        return -1;
    }
}
