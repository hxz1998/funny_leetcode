/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class No957 {
    public int[] prisonAfterNDays(int[] cells, int n) {
        // 记录当前的状态
        int state = 0;
        // 将数组状态转换成一个整数的 bit 状态
        for (int i = 0; i < 8; ++i) if (cells[i] > 0) state ^= (1 << i);
        // 将每一个状态对应的天数进行记录，因为这是一个 256 次的循环
        Map<Integer, Integer> seen = new HashMap<>();
        while (n > 0) {
            // 如果某一个状态已经经过记录了，就直接除于掉它
            if (seen.containsKey(state)) n %= seen.get(state) - n;
            // 然后再记录一个新的值
            seen.put(state, n);
            // 再把天数减去1，获取下一个状态
            if (n >= 1) {
                --n;
                state = nextDay(state);
            }
        }
        int[] ans = new int[8];
        for (int i = 0; i < 8; ++i) {
            if (((state >> i) & 1) > 0) ans[i] = 1;
        }
        return ans;
    }
    // 求下一个状态，下一个状态中间的每一位都是其两边两位的操作结果
    private int nextDay(int state) {
        int ret = 0;
        for (int i = 1; i <= 6; ++i) {
            if (((state >> (i - 1) & 1) == (state >> (i + 1) & 1))) ret ^= 1 << i;
        }
        return ret;
    }

    public static void main(String[] args) {
        int[] cells = {0, 1, 0, 1, 1, 0, 0, 1};
        No957 no957 = new No957();
        System.out.println(Arrays.toString(no957.prisonAfterNDays(cells, 7)));
    }
}
