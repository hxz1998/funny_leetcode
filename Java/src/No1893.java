/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1893 {
    public boolean isCovered(int[][] ranges, int left, int right) {
        boolean[] visited = new boolean[right + 1];
        for (int[] range : ranges) {
            for (int i = range[0]; i <= range[1]; ++i) if (i <= right) visited[i] = true;
        }
        for (int i = left; i <= right; ++i) if (!visited[i]) return false;
        return true;
    }
}
