/*
 * Copyright (c) 8/18/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No885 {
    private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // 记录下来总共要填充多少次
        int n = rows * cols;
        int[][] ans = new int[n][2];
        // 指向当前要填充的位置
        int idx = 0;
        ans[idx++] = new int[]{rStart, cStart};
        if (n == 1) return ans;
        // 按照 1, 1, 2, 2, 3, 3, 4, 4...这个规律递增，而且每次重复两次，所以使用 k 来指示当前需要增加多少次
        for (int k = 1; k < 2 * n; k += 2) {
            // 对四个方向进行扩展
            for (int i = 0; i < 4; ++i) {
                // 记录当前方向上需要走多少
                int steps = k + (i / 2);
                for (int j = 0; j < steps; ++j) {
                    rStart += dirs[i][0];
                    cStart += dirs[i][1];
                    // 如果当前步数在合理的矩形范围内，那么就添加进返回值中
                    if (rStart < rows && rStart >= 0 && cStart < cols && cStart >= 0) {
                        ans[idx++] = new int[]{rStart, cStart};
                        if (idx == n) return ans;
                    }
                }
            }
        }
        return ans;
    }
}
