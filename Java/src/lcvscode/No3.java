/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lcvscode;

public class No3 {
    private static int ans = 0;
    private static int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int largestArea(String[] grid) {
        int n = grid.length, m = grid[0].length();
        if (n == 1 || m == 1) return 0;
        char[][] charGrid = new char[n][m];
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < grid.length; ++i) charGrid[i] = grid[i].toCharArray();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || i == n - 1) {
                for (int j = 0; j < m; ++j) markCannot(charGrid, n, m, charGrid[i][j], i, j, visited);
            } else {
                markCannot(charGrid, n, m, charGrid[i][0], i, 0, visited);
                markCannot(charGrid, n, m, charGrid[i][m - 1], i, m - 1, visited);
            }
        }
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (charGrid[i][j] != '#') dfs(charGrid, n, m, charGrid[i][j], i, j, 0, visited);
            }
        }
        return ans;
    }

    private void markCannot(char[][] grid, int n, int m, char type, int x, int y, boolean[][] visited) {
        grid[x][y] = '#';
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == type && !visited[nx][ny])
                markCannot(grid, n, m, type, nx, ny, visited);
        }
    }

    private void dfs(char[][] grid, int n, int m, char type, int x, int y, int count, boolean[][] visited) {
        count++;
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == type && !visited[nx][ny])
                dfs(grid, n, m, type, nx, ny, count, visited);
        }
        ans = Math.max(count, ans);
    }

    public static void main(String[] args) {
        No3 no3 = new No3();
        String[] grid = {"111", "222", "333"};
        System.out.println(no3.largestArea(grid));
    }

}
