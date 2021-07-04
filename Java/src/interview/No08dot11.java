/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.HashMap;
import java.util.Map;

// 这个方法效率不高, 时间限制溢出
public class No08dot11 {
    private static final int MOD = 100_000_000_7;

    public int waysToChange(int n) {
        int[] coins = new int[]{25, 10, 5, 1};
        Map<int[], Integer> map = new HashMap<>();
        return makeChange(n, coins, 0, map);
    }

    private int makeChange(int amount, int[] coins, int idx, Map<int[], Integer> map) {
        if (map.containsKey(new int[]{amount, idx})) return map.get(new int[]{amount, idx});
        if (idx >= coins.length - 1) return 1;
        int coin = coins[idx];
        int ways = 0;
        for (int i = 0; i * coin <= amount; ++i) {
            ways %= MOD;
            ways += makeChange(amount - i * coin, coins, idx + 1, map);
        }
        map.put(new int[]{amount, idx}, ways);
        return ways;
    }

    public static void main(String[] args) {
        No08dot11 no08dot11 = new No08dot11();
        System.out.println(no08dot11.waysToChange(900750));
    }
}
