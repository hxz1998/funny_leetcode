/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No869 {
    public boolean reorderedPowerOf2(int N) {
        int[] A = count(N);
        for (int i = 0; i < 31; ++i) {
            // 对所有的 2 的倍数次进行检查，看看是否能匹配上
            if (Arrays.equals(A, count(1 << i))) return true;
        }
        return false;
    }

    // 对数字中每一个出现的数字进行统计个数
    private int[] count(int num) {
        int[] ret = new int[10];
        while (num > 0) {
            ret[num % 10]++;
            num /= 10;
        }
        return ret;
    }
}
