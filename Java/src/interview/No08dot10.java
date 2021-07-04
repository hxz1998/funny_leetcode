/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No08dot10 {
    private static int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        // 先记下来原来的颜色
        int color = image[sr][sc];
        // 然后深度优先搜索, 标记所有和 color 颜色一样的位置
        dfs(image, color, sr, sc);
        // 再逐个更新
        for (int i = 0; i < image.length; ++i) {
            for (int j = 0; j < image[0].length; ++j) {
                if (image[i][j] == -1) image[i][j] = newColor;
            }
        }
        return image;
    }

    private void dfs(int[][] image, int color, int x, int y) {
        // 标记当前位置为 -1
        image[x][y] = -1;
        for (int i = 0; i < 4; ++i) {
            // 四个方向进行搜索
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < image.length && ny >= 0 && ny < image[0].length && image[nx][ny] == color)
                dfs(image, color, nx, ny);
        }
    }

}
