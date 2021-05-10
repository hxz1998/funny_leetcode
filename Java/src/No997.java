/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No997 {
    public int findJudge(int N, int[][] trust) {
        // 入度为 N，出度为 0
        int[][] degree = new int[N][2];
        for (int[] item : trust) {
            degree[item[0]][0]++;
            degree[item[1]][1]++;
        }
        for (int i = 0; i < degree.length; ++i)
            if (degree[i][0] == 0 && degree[i][1] == N) return i + 1;
        return -1;
    }
}
