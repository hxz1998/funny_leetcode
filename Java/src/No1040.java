/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1040 {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int n = stones.length;
        int max = stones[n - 1] - stones[0] + 1 - n;
        max -= Math.min(stones[n - 1] - stones[n - 2] - 1, stones[1] - stones[0] - 1);
        int min = max;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) ++j;
            int cost = n - (j - i + 1);
            if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) cost = 2;
            min = Math.min(min, cost);
        }
        return new int[]{min, max};
    }
}
