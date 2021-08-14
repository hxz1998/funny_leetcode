/*
 * Copyright (c) 8/9/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No277 {
    private class Relation {
        boolean knows(int a, int b) {
            return false;
        }
    }

    public class Solution extends Relation {
        public int findCelebrity(int n) {
            int[] in = new int[n];
            int[] out = new int[n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (knows(i, j)) {
                        in[j]++;
                        out[i]++;
                    }
                }
            }
            for (int i = 0; i < n; ++i) if (in[i] == n && out[i] == 0) return i;
            return -1;
        }

    }
}
