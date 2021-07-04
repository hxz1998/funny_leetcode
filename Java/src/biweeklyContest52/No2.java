/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest52;

public class No2 {
    public int[] memLeak(int memory1, int memory2) {
        int[] ans = new int[3];
        int time = 1;
        while (true) {
            if (memory1 >= memory2) {
                if (memory1 < time) {
                    ans[0] = time;
                    ans[1] = memory1;
                    ans[2] = memory2;
                    return ans;
                }
                memory1 -= time;
            } else {
                if (memory2 < time) {
                    ans[0] = time;
                    ans[1] = memory1;
                    ans[2] = memory2;
                    return ans;
                }
                memory2 -= time;
            }
            time++;
        }
    }
}
