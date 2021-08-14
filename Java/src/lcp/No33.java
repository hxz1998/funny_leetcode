/*
 * Copyright (c) 8/13/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lcp;

public class No33 {
    public int storeWater(int[] bucket, int[] vat) {
        int n = bucket.length;
        int max = 0;
        for (int v : vat) max = Math.max(v, max);
        if (max == 0) return 0;
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= max; ++i) {
            int curr = i;
            for (int j = 0; j < n; ++j) {
                int least = (vat[j] - 1) / i + 1;
                curr += Math.max(least - bucket[i], 0);
            }
            ans = Math.min(ans, curr);
        }
        return ans;
    }
}
