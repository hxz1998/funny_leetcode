/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;

public class No939 {
    public int minAreaRect(int[][] points) {
        Map<Integer, TreeSet<Integer>> mapper = new TreeMap<>();
        for (int[] point : points) {
            if (mapper.containsKey(point[0])) mapper.get(point[0]).add(point[1]);
            else {
                TreeSet<Integer> set = new TreeSet<>();
                set.add(point[1]);
                mapper.put(point[0], set);
            }
        }
        int ans = Integer.MAX_VALUE;
        int size = points.length;
        for (int i = 0; i < size; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < size; ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                if (x1 == x2 || y1 == y2) continue;
                if (mapper.containsKey(x1) && mapper.containsKey(x2) && mapper.get(x1).contains(y2) && mapper.get(x2).contains(y1)) {
                    ans = Math.min(ans, Math.abs(x1 - x2) * Math.abs(y1 - y2));
                }
            }
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }

    public static void main(String[] args) {
        // [[3,2],[3,1],[4,4],[1,1],[4,3],[0,3],[0,2],[4,0]]
        int[][] points = new int[][]{{3, 2}, {3, 1}, {4, 4}, {1, 1}, {4, 3}, {0, 3}, {0, 2}, {4, 0}};
        No939 no939 = new No939();
        System.out.println(no939.minAreaRect(points));
    }
}
