/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No05dot08 {
    public int[] drawLine(int length, int w, int x1, int x2, int y) {
        int[] ans = new int[length];
        for (int i = x1; i <= x2; ++i) {
            int offset = (w / 32) * y + i / 32;
            ans[offset] |= 1 << (31 - i % 32);
        }
        return ans;
    }
}
