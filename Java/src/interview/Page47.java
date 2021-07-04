/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public interface Page47 {
    private static void allFib(int n) {
        int[] memo = new int[n];
        for (int i = 0; i < n; ++i) {
            System.out.println(fib(i, memo));
        }
    }

    private static int fib(int n, int[] memo) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (memo[n] > 0) return memo[n];

        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }

    public static void main(String[] args) {
        Page47.allFib(10);
    }
}
