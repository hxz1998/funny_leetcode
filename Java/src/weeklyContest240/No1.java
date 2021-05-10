/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest240;

public class No1 {
    public int maximumPopulation(int[][] logs) {
        int ans = 1950;
        int count = 0;
        for (int i = 1950; i <= 2050; ++i) {
            int tmp = 0;
            for (int[] log : logs) {
                if (log[0] <= i && log[1] > i) tmp++;
            }
            if (tmp > count) {
                count = tmp;
                ans = i;
            }
        }
        return ans;
    }
}
