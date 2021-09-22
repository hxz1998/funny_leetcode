/*
 * Copyright (c) 8/25/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class P1008 {
    public static void main(String[] args) {
        // 存储 1-9 使用过了没
        boolean[] used = new boolean[10];
        for (int i = 123; i < 333; ++i) {
            Arrays.fill(used, false);
            used[i % 10] = used[i / 10 % 10] = used[i / 100] =
                    used[2 * i % 10] = used[2 * i / 10 % 10] = used[2 * i / 100] =
                            used[3 * i % 10] = used[3 * i / 10 % 10] = used[3 * i / 100] = true;
            boolean isCorrected = true;
            for (int j = 1; j <= 9; ++j)
                if (!used[j]) {
                    isCorrected = false;
                    break;
                }
            if (isCorrected) System.out.printf("%d %d %d\n", i, i * 2, i * 3);
        }
    }
}
