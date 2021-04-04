/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1105 {
    public int minHeightShelves(int[][] books, int shelf_width) {
        int n = books.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[n] = 0;
        // 倒着处理书本，因为数组的最后一个在整个书架的最上面
        for (int i = n - 1; i >= 0; --i) {
            // 首先假设这一层高度为 0
            int maxHeight = 0;
            // 当前层剩余的宽度为 leftWidth
            int leftWidth = shelf_width;
            // 根据处理到的书以及之前出现的，尝试把之前出现的书放到当前层，看看能不能达到最小值
            for (int j = i; j < n && leftWidth >= books[j][0]; ++j) {
                maxHeight = Math.max(maxHeight, books[j][1]);
                dp[i] = Math.min(dp[i], maxHeight + dp[j + 1]);
                leftWidth -= books[j][0];
            }
        }
        return dp[0];
    }

    public static void main(String[] args) {
        int[][] books = {{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
        No1105 no1105 = new No1105();
        System.out.println(no1105.minHeightShelves(books, 4));
    }
}
