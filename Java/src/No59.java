/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No59 {
    public int[][] generateMatrix(int n) {
        // 用来填充返回矩阵
        int[][] matrix = new int[n][n];
        // 切换方向的四个值
        int[][] directions = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // row 记录当前行，column 记录当前列，currentDirection 记录当前方向
        int row = 0, column = 0, currentDirection = 0;
        // 从 1 到 n * n 挨个填充数据
        for (int i = 1; i <= n * n; ++i) {
            matrix[row][column] = i;
            // 使用当前方向，看看得到的新行和新列是否符合边界条件 [0, n) 以及是否访问过 (!= 0)
            int nr = row + directions[currentDirection][0], nc = column + directions[currentDirection][1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || matrix[nr][nc] != 0)
                // 如果碰到了边界，或者说已经填充过了，那么就切换方向
                currentDirection = (currentDirection + 1) % 4;
            // 这样求得的行号和列号一定是合法的
            row += directions[currentDirection][0];
            column += directions[currentDirection][1];
        }
        return matrix;
    }

    public static void main(String[] args) {
        No59 no59 = new No59();
        no59.generateMatrix(3);
    }
}
