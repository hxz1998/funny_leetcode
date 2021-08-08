/*
 * Copyright (c) 8/7/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.LinkedList;
import java.util.Queue;

public class No994 {
    private static final int[][] dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    public int orangesRotting(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        Queue<int[]> queue = new LinkedList<>();
        int cnt = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (grid[x][y] == 2) {
                    queue.offer(new int[]{x, y});
                    visited[x][y] = true;
                } else if (grid[x][y] == 1) cnt++;
            }
        }
        if (queue.isEmpty() && cnt != 0) return -1;
        int ans = 0;
        while (!queue.isEmpty()) {
            if (cnt == 0) break;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                int[] next = queue.poll();
                for (int j = 0; j < 4; ++j) {
                    assert next != null;
                    int nx = next[0] + dirs[j][0];
                    int ny = next[1] + dirs[j][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == 1) {
                        queue.offer(new int[]{nx, ny});
                        visited[nx][ny] = true;
                        grid[nx][ny] = 2;
                        cnt--;
                    }
                }
            }
            ans++;
        }
        return cnt == 0 ? ans : -1;
    }

    public static void main(String[] args) {
        int[][] grid = {{0}};
        No994 no944 = new No994();
        System.out.println(no944.orangesRotting(grid));
    }
}
