/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No05dot03 {
    public int reverseBits(int num) {
        if (~num == 0) return Integer.BYTES * 8;

        int curr = 0, prev = 0, ans = 1;
        while (num != 0) {
            if ((num & 1) == 1) curr++;
            else if ((num & 1) == 0) {
                prev = (num & 2) == 0 ? 0 : curr;
                curr = 0;
            }
            ans = Math.max(ans, prev + curr + 1);
            num >>>= 1;
        }
        return ans;
    }
}
