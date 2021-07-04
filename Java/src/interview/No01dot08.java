/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No01dot08 {
    public void setZeroes(int[][] matrix) {
        // 用来标记某一行或者某一列是否为 0
        boolean[] rowFlags = new boolean[matrix.length];
        boolean[] columnFlags = new boolean[matrix[0].length];
        // 遍历整个矩阵，对所有行和列进行标记
        for (int row = 0; row < matrix.length; ++row) {
            for (int column = 0; column < matrix[0].length; ++column) {
                if (matrix[row][column] == 0) {
                    // 标记 row 和 column 为出现了零的情况
                    rowFlags[row] = true;
                    columnFlags[column] = true;
                }
            }
        }
        // 根据标记情况，按行或者列进行置零
        for (int row = 0; row < rowFlags.length; ++row)
            if (rowFlags[row]) setRowZero(matrix, row);
        for (int column = 0; column < columnFlags.length; ++column)
            if (columnFlags[column]) setColumnZero(matrix, column);
    }

    // 把某一列置为 0
    private void setColumnZero(int[][] matrix, int column) {
        for (int i = 0; i < matrix.length; ++i) matrix[i][column] = 0;
    }
    // 把某一行置为 0
    private void setRowZero(int[][] matrix, int row) {
        for (int i = 0; i < matrix[0].length; ++i) matrix[row][i] = 0;
    }
}
