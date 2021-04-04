/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest235;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class No2 {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        Map<Integer, Set<Integer>> mapper = new HashMap<>();
        // logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
        for (int[] log : logs) {
            Set<Integer> set = mapper.getOrDefault(log[0], new HashSet<>());
            set.add(log[1]);
            mapper.put(log[0], set);
        }
        Map<Integer, Integer> count = new HashMap<>();
        for (Map.Entry<Integer, Set<Integer>> entry : mapper.entrySet()) {
            int activeTimes = entry.getValue().size();
            count.put(activeTimes, count.getOrDefault(activeTimes, 0) + 1);
        }

        int[] ans = new int[k];
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            ans[entry.getKey() - 1] = entry.getValue();
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] logs = {{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}};
        No2 no2 = new No2();
        System.out.println(no2.findingUsersActiveMinutes(logs, 5));
    }
}
