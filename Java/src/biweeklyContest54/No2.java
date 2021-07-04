/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest54;

import java.util.Arrays;

public class No2 {
    public int chalkReplacer(int[] chalk, int k) {
        long sum = 0;
        for (int num : chalk) sum += num;
        long kk = (long) k;
        kk %= sum;
        int idx = 0;
        while (true) {
            if (kk < chalk[idx]) return idx;
            kk -= chalk[idx];
            idx = (idx + 1) % chalk.length;
        }
    }

    public static void main(String[] args) {
        int[] chalk = {3,4,1,2};
        No2 no2 = new No2();
        System.out.println(no2.chalkReplacer(chalk, 25));
    }

}
