/*
 * Copyright (c) 8/13/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1578 {
    public int minCost(String s, int[] cost) {
        int idx = 0, len = s.length();
        int ans = 0;
        while (idx < len) {
            char c = s.charAt(idx);
            int maxValue = 0;
            int sum = 0;
            while (idx < len && s.charAt(idx) == c) {
                maxValue = Math.max(maxValue, cost[idx]);
                sum += cost[idx];
                idx++;
            }
            ans += sum - maxValue;
        }
        return ans;
    }
}
