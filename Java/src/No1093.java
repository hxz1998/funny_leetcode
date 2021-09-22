/*
 * Copyright (c) 8/22/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1093 {
    public double[] sampleStats(int[] count) {
        int median = 0, mode = 0;
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, cnt = 0, sum = 0;
        for (int k = 0; k < 256; ++k) {
            int i = count[k];
            if (i > 0) {
                min = Math.min(i, min);
                max = Math.max(max, i);
            }

        }
        return new double[]{min, max, 1.0 * sum / cnt, median, mode};
    }
}
