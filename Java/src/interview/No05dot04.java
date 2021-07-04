/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No05dot04 {
    public int[] findClosedNumbers(int num) {
        int[] ans = new int[2];
        ans[0] = getNext(num);
        ans[1] = getPrev(num);
        return ans;
    }

    private int getNext(int num) {
        int c = num;
        int c0 = 0, c1 = 0;
        while (c != 0 && ((c & 1) == 0)) {
            c0++;
            c >>= 1;
        }
        while ((c & 1) == 1) {
            c1++;
            c >>= 1;
        }

        if (c1 + c0 == 31 || c1 + c0 == 0) return -1;

        int position = c0 + c1;
        num |= (1 << position);
        num &= ~((1 << position) - 1);
        num |= (1 << (c1 - 1)) - 1;
        return num;
    }

    private int getPrev(int num) {
        int c = num;
        int c0 = 0, c1 = 0;
        while ((c & 1) == 1) {
            c1++;
            c >>= 1;
        }
        if (c == 0) return -1;
        while (((c & 1) == 0) && c != 0) {
            c >>= 1;
            c0++;
        }

        int position = c0 + c1;
        num &= ((~0) << (position + 1));
        int mask = (1 << (c1 + 1)) - 1;
        num |= mask << (c0 - 1);
        return num;
    }
}
