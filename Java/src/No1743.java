/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No1743 {
    public int[] restoreArray(int[][] adjacentPairs) {
        Map<Integer, List<Integer>> mapper = new HashMap<>();
        int n = adjacentPairs.length;
        for (int[] pair : adjacentPairs) {
            List<Integer> list = mapper.getOrDefault(pair[0], new ArrayList<>());
            list.add(pair[1]);
            mapper.put(pair[0], list);
            list = mapper.getOrDefault(pair[1], new ArrayList<>());
            list.add(pair[0]);
            mapper.put(pair[1], list);
        }
        int id = 0;
        for (Map.Entry<Integer, List<Integer>> entry : mapper.entrySet()) {
            if (entry.getValue().size() == 1) {
                id = entry.getKey();
                break;
            }
        }
        int[] ans = new int[n + 1];
        ans[0] = id;
        id = mapper.get(id).get(0);
        ans[1] = id;
        if (n == 1) return ans;
        for (int idx = 2; idx <= n; ++idx) {
            id = mapper.get(id).get(0) == ans[idx - 2] ? mapper.get(id).get(1) : mapper.get(id).get(0);
            ans[idx] = id;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] adjacentPairs = {{2, 1}, {4, 3}, {3, 2}};
        No1743 no1743 = new No1743();
        System.out.println(Arrays.toString(no1743.restoreArray(adjacentPairs)));
    }
}
