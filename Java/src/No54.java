/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No54 {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        int rows = matrix.length, columns = matrix[0].length;
        boolean[][] visited = new boolean[rows][columns];
        int total = rows * columns, currentDirection = 0;
        // 关键在于这个方向变化矩阵的设置，方便了很多操作，省去了很多 if-else
        // 配合使用 currentDirection 可以实现四个方向的轮流旋转
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int row = 0, column = 0;
        for (int i = 0; i < total; ++i) {
            list.add(matrix[row][column]);
            visited[row][column] = true;
            int newRow = row + directions[currentDirection][0], newColumn = column + directions[currentDirection][1];
            if (newRow < 0 || newRow >= rows || newColumn < 0 || newColumn >= columns || visited[newRow][newColumn]) {
                currentDirection = (currentDirection + 1) % 4;
            }
            row += directions[currentDirection][0];
            column += directions[currentDirection][1];
        }
        return list;
    }
}
