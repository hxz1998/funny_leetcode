/*
 * Copyright (c) 9/4/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package offer;

import java.util.Arrays;

public class No10_1 {
    private static final int MOD = (int) 1e9 + 7;

    public int fib(int n) {
        if (n == 1) return 1;
        if (n == 0) return 0;
        int[] memo = new int[n + 1];
        Arrays.fill(memo, 0);
        memo[0] = 0;
        memo[1] = 1;
        return helper(n, memo);
    }

    private int helper(int n, int[] memo) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (memo[n] != 0) return memo[n];
        memo[n] = helper(n - 1, memo) % MOD + helper(n - 2, memo) % MOD;
        return memo[n] % MOD;
    }

    public static void main(String[] args) {
        No10_1 no10_1 = new No10_1();
        System.out.println(no10_1.fib(44));
        System.out.println(no10_1.fib(7));
    }
}
