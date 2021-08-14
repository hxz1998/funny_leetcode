/*
 * Copyright (c) 8/11/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No446 {
    public int numberOfArithmeticSlices(int[] nums) {
        int ans = 0;
        int n = nums.length;
        Map<Long, Integer>[] mapper = new Map[n];
        for (int i = 0; i < n; ++i) mapper[i] = new HashMap<>();
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                long d = 1L * nums[j] - nums[i];
                int cnt = mapper[i].getOrDefault(d, 0);
                ans += cnt;
                mapper[i].put(d, mapper[j].getOrDefault(d, 0) + cnt + 1);
            }
        }
        return ans;
    }
}
