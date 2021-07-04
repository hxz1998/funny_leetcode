/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest248;

import java.util.Arrays;

public class No2 {
    public int eliminateMaximum(int[] dist, int[] speed) {
        int ans = 0, n = dist.length;
        double[] times = new double[n];
        for (int i = 0; i < n; ++i) times[i] = 1.0 * dist[i] / speed[i];
        Arrays.sort(times);
        for (int i = 1; i <= n; ++i) {
            if (i - 1 >= times[i - 1]) return ans;
            ans++;
        }
        return ans;
    }
}
