/**
 * Created by Xiaozhong on 2021/1/30.
 * Copyright (c) 2021/1/30 Xiaozhong. All rights reserved.
 */

public class No778 {
    private int N = 0;
    private int[][] dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    public int swimInWater(int[][] grid) {
        N = grid.length;
        int left = 0, right = N * N - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            boolean[][] visited = new boolean[N][N];
            if (grid[0][0] <= mid && dfs(grid, 0, 0, visited, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean dfs(int[][] grid, int x, int y, boolean[][] visited, int threshold) {
        visited[x][y] = true;
        for (int[] direction : dir) {
            int nx = x + direction[0];
            int ny = y + direction[1];
            if (inArea(nx, ny) && !visited[nx][ny] && grid[nx][ny] <= threshold) {
                if (nx == N - 1 && ny == N - 1) {
                    return true;
                }
                if (dfs(grid, nx, ny, visited, threshold)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean inArea(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }
}
