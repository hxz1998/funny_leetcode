/*
 * Copyright (c) 9/14/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No447 {
    private int distance(int[] a, int[] b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }

    public int numberOfBoomerangs(int[][] points) {
        int ans = 0;
        for (int[] ints : points) {
            Map<Integer, Integer> mapper = new HashMap<>();
            for (int[] point : points) {
                int dist = distance(ints, point);
                mapper.put(dist, mapper.getOrDefault(dist, 0) + 1);
            }
            for (Map.Entry<Integer, Integer> entry : mapper.entrySet()) {
                if (entry.getValue() >= 2) ans += entry.getValue() * (entry.getValue() - 1);
            }
        }
        return ans;
    }
}
