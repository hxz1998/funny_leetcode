/*
 * Copyright (c) 8/5/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashSet;
import java.util.Set;

public class No983 {
    private int[] costs;
    private Set<Integer> daySet;
    private Integer[] memo;

    public int mincostTickets(int[] days, int[] costs) {
        this.costs = costs;
        memo = new Integer[366];
        daySet = new HashSet<>();
        for (int day : days) daySet.add(day);
        // 返回从第一天到最后一天所用的最低花费
        return dp(1);
    }

    // 从 day 到最后一天的最低消费
    private int dp(int day) {
        if (day > 365) return 0;
        if (memo[day] != null) return memo[day];
        if (daySet.contains(day)) {
            memo[day] = Math.min(Math.min(dp(day + 1) + costs[0], dp(day + 7) + costs[1]),
                    dp(day + 30) + costs[30]);
        } else {
            memo[day] = dp(day + 1);
        }
        return memo[day];
    }
}
