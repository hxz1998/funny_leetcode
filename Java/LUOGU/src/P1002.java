/*
 * Copyright (c) 8/23/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Scanner;

/**
 * 2021年8月24日，可算 Accept 了
 * 类似于动态规划
 */
public class P1002 {
    private static final int[][] horseDirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    private static final int n = 40;
    private static final int m = 40;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] target = {scanner.nextInt(), scanner.nextInt()};
        int[] horse = {scanner.nextInt(), scanner.nextInt()};
        boolean[][] cannot = new boolean[n][m];
        for (int[] point : horseDirs) {
            int nx = horse[0] + point[0];
            int ny = horse[1] + point[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) cannot[nx][ny] = true;
        }
        cannot[horse[0]][horse[1]] = true;
        long[][] cnt = new long[n][m];
        for (int i = 0; i <= target[0]; ++i) {
            for (int j = 0; j <= target[1]; ++j) {
                if (cannot[i][j]) continue;
                if (i == 0 && j == 0) cnt[i][j] = 1L;
                else if (i == 0) cnt[i][j] = cnt[i][j - 1];
                else if (j == 0) cnt[i][j] = cnt[i - 1][j];
                else cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1];
            }
        }
        System.out.println(cnt[target[0]][target[1]]);
    }
}
