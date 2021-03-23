/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest48;

import java.util.Arrays;

public class No3 {
    public int getMaximumConsecutive(int[] coins) {
        int x = 0;
        Arrays.sort(coins);
        for (int coin : coins) {
            if (coin > x + 1) break;
            x += coin;
        }
        return x + 1;
    }

    public static void main(String[] args) {
        No3 no3 = new No3();
        int[] coins = {1, 1, 1, 4};
        System.out.println(no3.getMaximumConsecutive(coins));
    }
}
