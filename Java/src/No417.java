/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No417 {
    // 用来返回的返回值
    private List<List<Integer>> ans = new ArrayList<>();
    // 方向转换的数组
    private int[][] dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    // 大西洋和太平洋共享的访问数组
    private boolean[][] visited = null;

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int n = heights.length, m = heights[0].length;
        visited = new boolean[n][m];
        // temp 是用来记录当前深度优先搜索访问过的点
        boolean[][] temp = new boolean[n][m];
        // 首先从太平洋出发，看看都能遇到哪些点
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                // x == 0 || y == 0 表示要从太平洋出发需要满足的条件，flag == false 意味着是从太平洋出发的
                if ((x == 0 || y == 0) && !temp[x][y]) dfs(heights, x, y, temp, n, m, false);
            }
        }
        // 同上，temp 是用来标记当前深度优先搜索访问到的点
        temp = new boolean[n][m];
        // 然后再从大西洋出发，看看能遇到哪些点，如果遇到的点 在 visited 中之前已经被标记为 true， 那么说明双方都可到达
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                // x == n - 1 || y == m - 1 表示从大西洋出发
                if ((x == n - 1 || y == m - 1) && !temp[x][y]) dfs(heights, x, y, temp, n, m, true);
            }
        }
        return ans;
    }

    /**
     * @param x         深度优先搜索的起始点坐标 x
     * @param y         起始点坐标 y
     * @param temp      用来标记当前深度优先搜索已经访问过哪些点了
     * @param flag      为 true 时意味着是大西洋来的，为 false 意味着是太平洋来的
     */
    private void dfs(int[][] heights, int x, int y, boolean[][] temp, int n, int m, boolean flag) {
        // 如果是大西洋来的，而且 太平洋已经访问过 {x, y} 了，就放到返回值中
        if (flag && visited[x][y]) {
            List<Integer> buf = new ArrayList<>();
            buf.add(x);
            buf.add(y);
            ans.add(buf);
            // 顺便把该点置为 false，防止重复记录
            visited[x][y] = false;
        }
        // 如果是从太平洋来的，需要将 {x, y} 标记为已来过
        if (!flag) visited[x][y] = true;
        // 然后切换四个方向，逐个检查
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            // 检查新的坐标是否合法，以及当前深度优先搜索是否来过，最后还要满足 逆向 条件
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !temp[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                temp[nx][ny] = true;    // 然后在当前深度优先搜索中标记为已来过
                dfs(heights, nx, ny, temp, n, m, flag); // 继续深度优先搜索
            }
        }
    }
}
