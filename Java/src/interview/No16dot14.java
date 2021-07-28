/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No16dot14 {
    public int[] bestLine(int[][] points) {
        int n = points.length;
        int[] ans = null;
        int maxCount = 0, count = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                count = 2;
                if (n - (j + 1) + 2 <= maxCount) break;
                long dx1 = points[j][0] - points[i][0];
                long dy1 = points[j][1] - points[i][1];
                for (int k = j + 1; k < n; ++k) {
                    long dx2 = points[k][0] - points[j][0];
                    long dy2 = points[k][1] - points[j][1];
                    if (dx1 * dy2 == dx2 * dy1) count++;
                }
                if (count > maxCount) {
                    maxCount = count;
                    ans = new int[]{i, j};
                }
            }
        }
        return ans;
    }
}
