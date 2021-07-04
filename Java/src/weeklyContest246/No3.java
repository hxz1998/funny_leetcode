/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest246;

public class No3 {
    private int[][] src, dist;
    private int m, n;
    // 用来标记当前岛屿是不是构成子岛屿
    boolean flag = true;
    private int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        src = grid1;
        dist = grid2;
        m = grid1.length;
        n = grid1[0].length;
        // 标记是否访问过该位置
        boolean[][] visited = new boolean[m][n];
        // 最后的返回值
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 如果对于grid1和grid2中 (i, j) 位置两个都是岛屿而且没访问过, 那么就进行检查
                if (grid2[i][j] == 1 && grid1[i][j] == 1 && !visited[i][j]) {
                    flag = true;
                    // 深度优先搜索
                    dfs(i, j, visited);
                    // 如果符合条件, 那么就累加结果
                    if (flag) ++count;
                }
            }
        }
        return count;
    }

    private void dfs(int x, int y, boolean[][] visited) {
        // 首先标记访问过 (x, y) 了
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            // 上下左右四个方向挨个走
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            // 如果位置没有越界, 而且也没访问过 (nx, ny), 并且是一个岛屿(dist[nx][ny] == 1), 我们就接着深度优先搜索
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && dist[nx][ny] == 1) {
                // 如果发现在 grid1 中该位置上不是岛屿, 那么就更换标记
                if (src[nx][ny] == 0) flag = false;
                dfs(nx, ny, visited);
            }
        }
    }

    public static void main(String[] args) {
        int[][] grid1 = {{1, 1, 1, 1, 0, 0}, {1, 1, 0, 1, 0, 0}, {1, 0, 0, 1, 1, 1}, {1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 1, 1}, {1, 0, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 0}};
        int[][] grid2 = {{1, 1, 1, 1, 0, 1}, {0, 0, 1, 0, 1, 0}, {1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0}, {0, 1, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0}};
        No3 no3 = new No3();
        System.out.println(no3.countSubIslands(grid1, grid2));
    }
}
