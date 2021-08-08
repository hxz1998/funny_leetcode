/*
 * Copyright (c) 8/7/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.LinkedList;
import java.util.Queue;

public class No1091 {
    private static final int[][] dirs = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};

    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        if (grid[0][0] == 1) return -1;
        if (n == 1 && grid[0][0] == 0) return 1;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        boolean[][] visited = new boolean[n][m];
        int ans = 1;
        visited[0][0] = true;
        boolean isArrived = false;
        while (!queue.isEmpty() && !isArrived) {
            ++ans;
            int size = queue.size();
            for (int i = 0; i < size && !isArrived; ++i) {
                int[] next = queue.poll();
                for (int j = 0; j < 8 && !isArrived; ++j) {
                    assert next != null;
                    int nx = next[0] + dirs[j][0];
                    int ny = next[1] + dirs[j][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == 0) {
                        if (nx == n - 1 && ny == m - 1) isArrived = true;
                        queue.offer(new int[]{nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return isArrived ? ans : -1;
    }
}
