/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No17dot01 {
    public int add(int a, int b) {
        int m = a ^ b;
        int n = (a & b) << 1;
        while (n != 0) {
            int t = m ^ n;
            n = (n & m) << 1;
            m = t;
        }
        return m;
    }
}
