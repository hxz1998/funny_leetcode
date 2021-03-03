/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No338 {
    public int[] countBits(int num) {
        int[] ans = new int[num + 1];
        ans[0] = 0;
        for (int i = 1; i <= num; ++i) {
            if (i % 2 == 0) ans[i] = ans[i / 2];
            else ans[i] = ans[i - 1] + 1;
        }
        return ans;
    }
}
