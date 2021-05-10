/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest237;

import java.util.Arrays;

public class No2 {

    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int ans = 0;
        for (int item : costs) {
            if (coins >= item) {
                coins -= item;
                ++ans;
            }
        }
        return ans;
    }

    private void backtrace(int[] costs, int start, int remain, int count) {
        if (remain < costs[start]) return;
    }

    public static void main(String[] args) {

    }
}
