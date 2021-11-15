/*
 * Copyright (c) 10/24/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package contest15.no1;

import java.util.Scanner;

public class Main {
    private static int tmp = 0;
    private static final int mod = 998244353;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        for (int i = 1; i <= k; ++i) {
            if (i > n) System.out.print(0 + " ");
            tmp = 0;
            dfs(n, 1, 1, i, true);
            dfs(n, 1, 1, i, false);
            dfs(n, 1, 2, i, true);
            dfs(n, 1, 2, i, false);
            System.out.print(tmp % mod + " ");
        }
    }

    private static void dfs(int n, int start, int size, int remain, boolean selected) {
        if (start > n || remain == 0) return;
        tmp %= mod;
//        dfs(n, start + 1, size, )
    }
}
