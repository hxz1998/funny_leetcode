/*
 * Copyright (c) 8/25/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Scanner;

public class P1007 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int L = scanner.nextInt();
        int n = scanner.nextInt();
        if (n == 0) {
            System.out.println("0 0");
            return;
        }
        int min = Integer.MIN_VALUE, max = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            int pos = scanner.nextInt();
            int mn = Math.min(L - pos + 1, pos);
            int mx = Math.max(L - pos + 1, pos);
            min = Math.max(min, mn);
            max = Math.max(max, mx);
        }
        System.out.printf("%d %d", min, max);
    }
}
