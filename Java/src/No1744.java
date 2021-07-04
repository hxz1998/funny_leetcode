/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1744 {
    public boolean[] canEat(int[] candiesCount, int[][] queries) {
        int n = candiesCount.length;
        long[] sum = new long[n];

        sum[0] = candiesCount[0];
        for (int i = 1; i < n; ++i) sum[i] = sum[i - 1] + candiesCount[i];

        int q = queries.length;
        boolean[] ans = new boolean[q];
        for (int i = 0; i < q; ++i) {
            int[] query = queries[i];
            int type = query[0], day = query[1], cap = query[2];
            long x1 = day + 1;
            long y1 = (long) (day + 1) * cap;
            long x2 = type == 0 ? 1 : sum[type - 1] + 1;
            long y2 = sum[type];

            ans[i] = !(x1 > y2 || y1 < x2);
        }
        return ans;
    }
}
