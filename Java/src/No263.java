/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No263 {
    public boolean isUgly(int n) {
        if (n == 0) return false;
        if (n == 1 || n == 2 || n == 3 || n == 5) return true;
        if (n % 2 == 0 && isUgly(n / 2) ||
                n % 3 == 0 && isUgly(n / 3) ||
                n % 5 == 0 && isUgly(n / 5)) return true;
        return false;
    }
}
