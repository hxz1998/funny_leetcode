/*
 * Copyright (c) 9/11/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lccup2021fall;

import java.util.Arrays;

public class No2 {
    private static class Pair {
        int sum = 0, cnt = 0;

        public Pair(int sum, int cnt) {
            this.sum = sum;
            this.cnt = cnt;
        }
    }

    public int maxmiumScore(int[] data, int cnt) {
        int n = data.length;
        Integer[] cards = new Integer[n];
        for (int i = 0; i < n; ++i) cards[i] = data[i];
        Arrays.sort(cards, (o1, o2) -> o2 - o1);
        Pair[][] dp = new Pair[n][2];
        // 0 偶数， 1 奇数
        dp[0][0] = cards[0] % 2 == 0 ? new Pair(cards[0], 1) : new Pair(0, 0);
        dp[0][1] = cards[0] % 2 == 0 ? new Pair(0, 0) : new Pair(cards[0], 1);
        for (int i = 1; i < n; ++i) {
            if (cards[i] % 2 == 0) {
                dp[i][0] = new Pair(dp[i - 1][0].sum + cards[i], dp[i - 1][0].cnt + 1);
                dp[i][1] = new Pair(dp[i - 1][1].sum + cards[i], dp[i - 1][1].cnt + 1);
            } else {
                dp[i][0] = dp[i - 1][0].sum > dp[i - 1][1].sum + cards[i] ? new Pair(dp[i - 1][0].sum, dp[i - 1][0].cnt) :
                        dp[i - 1][0].sum == dp[i - 1][1].sum + cards[i] ?
                                dp[i - 1][0].cnt > dp[i - 1][1].cnt + 1 ? new Pair(dp[i - 1][1].sum + cards[i], dp[i - 1][1].cnt + 1) : new Pair(dp[i - 1][0].sum, dp[i - 1][0].cnt) :
                                new Pair(dp[i - 1][1].sum + cards[i], dp[i - 1][1].cnt + 1);

                dp[i][1] = dp[i - 1][0].sum + cards[i] < dp[i - 1][1].sum ? new Pair(dp[i - 1][1].sum, dp[i - 1][1].cnt) :
                        dp[i - 1][0].sum + cards[i] == dp[i - 1][1].sum ?
                                dp[i - 1][0].cnt + 1 < dp[i - 1][1].cnt ? new Pair(dp[i - 1][0].sum + cards[i], dp[i - 1][0].cnt + 1) : new Pair(dp[i - 1][1].sum, dp[i - 1][1].cnt) :
                                new Pair(dp[i - 1][0].sum + cards[i], dp[i - 1][0].cnt + 1);
            }
            if (dp[i][0].cnt == cnt) return dp[i][0].sum;
        }
        return dp[n - 1][0].cnt == cnt ? dp[n - 1][0].sum : 0;
    }

    public static void main(String[] args) {
        int[] cards = {1, 2, 8, 9};
        No2 no2 = new No2();
        System.out.println(no2.maxmiumScore(cards, 3));
    }
}
