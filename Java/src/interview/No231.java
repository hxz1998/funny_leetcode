/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No231 {
    public boolean isPowerOfTwo(int n) {
        int num = 0;
        while (num < 31) {
            if (n == (1 << num)) return true;
            num++;
        }
        return false;
    }
}
