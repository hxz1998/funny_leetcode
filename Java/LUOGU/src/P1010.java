/*
 * Copyright (c) 8/30/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Scanner;

public class P1010 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        StringBuilder builder = covert(num);
        int idx = check(builder);
        while (idx != -1) {
            int n = 0;
            int right = idx;
            while (Character.isDigit(builder.charAt(right))) {
                n = n * 10 + builder.charAt(right) - '0';
                right++;
            }
            builder = new StringBuilder(builder.substring(0, idx) +
                    covert(n) +
                    builder.substring(right));
            idx = check(builder);
        }
        System.out.println(builder.toString());
    }

    private static int check(StringBuilder builder) {
        for (int idx = 0; idx < builder.length(); ++idx) {
            char c = builder.charAt(idx);
            if (c != '(' && c != ')' && c != '2' && c != '0' && c != '+') return idx;
        }
        return -1;
    }

    private static StringBuilder covert(int num) {
        StringBuilder builder = new StringBuilder();
        while (num > 0) {
            int e = 0;
            while (Math.pow(2, e + 1) <= num) e++;
            num -= Math.pow(2, e);
            if (e == 1) builder.append(2).append("+");
            else builder.append(2).append("(").append(e).append(")").append("+");
        }
        return builder.deleteCharAt(builder.length() - 1);
    }
}
