/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest244;

import java.util.Arrays;

public class No1 {
    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;
        boolean flag = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!flag || mat[i][j] != target[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) return true;
        for (int i = 0; i < 4; ++i) {
            mat = rotation(mat);
            if (Arrays.deepEquals(mat, target)) return true;
        }
        return false;
    }

    int[][] rotation(int[][] mat) {
        int n = mat.length;
        int[][] ans = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][i] = mat[i][j];
            }
        }
        return ans;
    }
}
