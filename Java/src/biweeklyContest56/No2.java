/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest56;

import java.util.LinkedList;
import java.util.Queue;

public class No2 {
    private int ans = Integer.MAX_VALUE;
    private int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private int n, m;
    private int startX, startY;

    public int nearestExit(char[][] maze, int[] entrance) {
        ans = Integer.MAX_VALUE;
        n = maze.length;
        m = maze[0].length;
        startX = entrance[0];
        startY = entrance[1];
        int[][] steps = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) steps[i][j] = Integer.MAX_VALUE;
        }
        steps[entrance[0]][entrance[1]] = 0;
        boolean[][] visited = new boolean[n][m];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(entrance);
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                int[] next = queue.poll();
                for (int j = 0; j < 4; ++j) {
                    int nx = next[0] + dirs[j][0];
                    int ny = next[1] + dirs[j][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && maze[nx][ny] == '.') {
                        if (nx == startX && ny == startY) continue;
                        visited[nx][ny] = true;
                        steps[nx][ny] = steps[next[0]][next[1]] + 1;
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0 || i == n - 1) {
                for (int j = 0; j < m; ++j) {
                    if (!(i == startX && j == startY)) ans = Math.min(ans, steps[i][j]);
                }
            } else {
                if (!(i == startX && 0 == startY)) ans = Math.min(ans, steps[i][0]);
                if (!(i == startX && m - 1 == startY)) ans = Math.min(ans, steps[i][m - 1]);
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    private void dfs(char[][] maze, int x, int y, boolean[][] visited, int steps) {
        if ((x == 0 || y == 0 || x == n - 1 || y == m - 1) && !(x == startX && y == startY)) {
            ans = Math.min(steps, ans);
            return;
        }
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx == startX && ny == startY) continue;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.' && !visited[nx][ny])
                dfs(maze, nx, ny, visited, steps + 1);
        }
        visited[x][y] = false;
    }

    public static void main(String[] args) {
        char[][] maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
        No2 no2 = new No2();
        int[] ent = {1, 2};
        System.out.println(no2.nearestExit(maze, ent));
        maze = new char[][]{{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
        ent = new int[]{1, 0};
        System.out.println(no2.nearestExit(maze, ent));

    }
}
