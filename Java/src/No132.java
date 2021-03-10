/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No132 {
    public int minCut(String s) {
        int size = s.length();
        boolean[][] g = new boolean[size][size];
        for (int i = 0; i < size; ++i) Arrays.fill(g[i], true);
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i + 1; j < size; ++j) {
                g[i][j] = s.charAt(i) == s.charAt(j) && g[i + 1][j - 1];
            }
        }
        int[] f = new int[size];
        Arrays.fill(f, Integer.MAX_VALUE);
        for (int i = 0; i < size; ++i) {
            if (g[0][i]) f[i] = 0;
            else {
                for (int j = 0; j < i; ++j) {
                    if (g[j + 1][i]) f[i] = Math.min(f[i], f[j] + 1);
                }
            }
        }
        return f[size - 1];
    }
}
