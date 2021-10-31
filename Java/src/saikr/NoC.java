/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package saikr;

import java.util.Arrays;
import java.util.Scanner;

public class NoC {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int curr = Integer.MAX_VALUE, prev = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            int num = scanner.nextInt();
            if (curr == Integer.MAX_VALUE) curr = num;
            else if (prev == Integer.MAX_VALUE) {
                prev = Math.max(num, curr);
                curr = Math.min(num, curr);
            } else {
                if (num < curr) {
                    prev = curr;
                    curr = num;
                } else if (num < prev) prev = num;
            }
        }
        System.out.println(prev);
    }
}
