/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1051 {
    public int heightChecker(int[] heights) {
        int[] arr = new int[101];
        for (int height : heights) arr[height]++;
        int ans = 0;
        for (int i = 1, j = 0; i < arr.length; ++i) {
            while (arr[i]-- > 0) {
                if (heights[j++] != i) ++ans;
            }
        }
        return ans;
    }
}
