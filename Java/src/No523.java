/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No523 {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        if (n < 2) return false;
        Map<Integer, Integer> mapper = new HashMap<>();
        mapper.put(0, -1);
        int remainder = 0;
        for (int i = 0; i < n; ++i) {
            remainder = (remainder + nums[i]) % k;
            if (mapper.containsKey(remainder)) {
                int prevIndex = mapper.get(remainder);
                if (i - prevIndex >= 2) return true;
            } else mapper.put(remainder, i);
        }
        return false;
    }
}
