/*
 * Copyright (c) 8/1/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest252;

public class No1 {
    public boolean isThree(int n) {
        int cnt = 0;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (n / i != i) cnt += 2;
                else cnt += 1;
            }
        }
        return cnt == 3;
    }
}
