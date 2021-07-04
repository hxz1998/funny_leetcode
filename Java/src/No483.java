/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No483 {
    public String smallestGoodBase(String n) {
        long num = Long.parseLong(n);
        int max = (int) Math.floor(Math.log(num) / Math.log(2));
        for (int m = max; m > 1; --m) {
            // k 进制
            int k = (int) Math.pow(num, 1.0 / m);
            long base = 1, sum = 1;
            for (int i = 0; i < m; ++i) {
                base *= k;
                sum += base;
            }
            if (sum == num) return Integer.toString(k);
        }
        return Long.toString(num - 1);
    }
}
