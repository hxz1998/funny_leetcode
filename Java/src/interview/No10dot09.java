/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No10dot09 {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) return false;
        int m = matrix.length, n = matrix[0].length;
        int x = m - 1, y = 0;
        while (x >= 0 && x < m && y >= 0 && y < n) {
            if (matrix[x][y] < target) ++y;
            else if (matrix[x][y] > target) --x;
            else return true;
        }
        return false;
    }
}
