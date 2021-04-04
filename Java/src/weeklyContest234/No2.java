/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest234;

import java.util.HashMap;
import java.util.Map;

public class No2 {
    public int reinitializePermutation(int n) {
        if (n == 2) return 1;
        int idx = 2, ret = 1;
        while (true) {
            if (idx == 1) break;
            if (2 * idx < n) idx = 2 * idx;
            else idx = 2 * idx + 1 - n;
            ret++;
        }
        return ret;
    }

    public static void main(String[] args) {
        No2 no2 = new No2();
        System.out.println(no2.reinitializePermutation(6));
        System.out.println(no2.reinitializePermutation(10));
    }
}
