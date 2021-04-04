/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest49;

import java.util.HashMap;
import java.util.Map;

public class No3 {
    private int reverse(int num) {
        return Integer.parseInt(new StringBuilder(Integer.toString(num)).reverse().toString());
    }

    public int countNicePairs(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> count = new HashMap<>();
        int ans = 0, mod = 1_000_000_007;
        for (int i = 0; i < n; ++i) {
            int value = nums[i] - reverse(nums[i]);
            int c = count.getOrDefault(value, 0);
            count.put(value, c + 1);
            ans += c % mod;
            ans %= mod;
        }
        return ans;
    }

    public static void main(String[] args) {

    }
}
