/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No325 {
    public int maxSubArrayLen(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> preSumIndex = new HashMap<>();
        int ans = 0;
        int preSum = 0;
        preSumIndex.put(0, -1);
        for (int i = 0; i < n; ++i) {
            preSum += nums[i];
            if (!preSumIndex.containsKey(preSum)) {
                preSumIndex.put(preSum, i);
            }
            if (preSumIndex.containsKey(preSum - k)) {
                ans = Math.max(ans, i - preSumIndex.get(preSum - k));
            }
        }
        return ans;
    }
}
