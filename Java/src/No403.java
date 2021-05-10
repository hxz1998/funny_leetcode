/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No403 {
    // 表示的是 visited[i][j] 从 i 出发，上次距离为 j 时是否可行
    Boolean[][] visited;

    public boolean canCross(int[] stones) {
        int n = stones.length;
        visited = new Boolean[n][n];
        return dfs(stones, 0, 0);
    }

    private boolean dfs(int[] stones, int start, int lastDistance) {
        if (start == stones.length - 1) return true;
        if (visited[start][lastDistance] != null) return visited[start][lastDistance];

        for (int curDistance = lastDistance - 1; curDistance <= lastDistance + 1; ++curDistance) {
            if (curDistance > 0) {
                int j = Arrays.binarySearch(stones, start, stones.length, curDistance + stones[start]);
                if (j >= 0 && dfs(stones, j, curDistance)) return visited[start][lastDistance] = true;
            }
        }
        return visited[start][lastDistance] = false;
    }

    public static void main(String[] args) {
        System.out.println(8 >> 1);
    }
}
