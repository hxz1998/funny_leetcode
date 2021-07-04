/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest245;

public class No3 {
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        int x = 0, y = 0, z = 0;
        for (int[] triple : triplets) {
            if (triple[0] <= target[0] && triple[1] <= target[1] && triple[2] <= target[2]) {
                x = Math.max(x, triple[0]);
                y = Math.max(y, triple[1]);
                z = Math.max(z, triple[2]);
            }
        }
        return x == target[0] && y == target[1] && z == target[2];
    }
}
