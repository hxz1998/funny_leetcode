/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No1711 {
    private static final int MOD = 1_000_000_007;

    public int countPairs(int[] deliciousness) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (int i = 0; i < deliciousness.length; ++i) {
            for (int j = 0; j < 22; ++j) {
                int target = 1 << j;
                if (target - deliciousness[i] < 0) continue;
                else if (cnt.containsKey(target - deliciousness[i])) {
                    ans += cnt.get(target - deliciousness[i]);
                }
                ans %= MOD;
            }
            cnt.put(deliciousness[i], cnt.getOrDefault(deliciousness[i], 0) + 1);
        }
        return ans % MOD;
    }
}
