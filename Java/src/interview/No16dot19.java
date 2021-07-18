/*
 * Copyright (c) 7/13/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class No16dot19 {
    private int area;
    private int[][] dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    private int m = 0, n = 0;

    public int[] pondSizes(int[][] land) {
        List<Integer> list = new ArrayList<>();
        m = land.length;
        n = land[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                area = 0;
                if (!visited[x][y] && land[x][y] == 0) dfs(land, x, y, visited);
                if (area != 0) list.add(area);
            }
        }
        int[] ans = new int[list.size()];
        list.sort((Comparator.comparingInt(o -> o)));
        for (int i = 0; i < list.size(); ++i) ans[i] = list.get(i);
        return ans;
    }

    private void dfs(int[][] land, int x, int y, boolean[][] visited) {
        visited[x][y] = true;
        area++;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && land[nx][ny] == 0)
                dfs(land, nx, ny, visited);
        }
    }
}
