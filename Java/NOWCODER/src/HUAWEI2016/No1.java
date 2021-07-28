/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package HUAWEI2016;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class No1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int[] studentScores = new int[N + 1];
            for (int i = 0; i < N; ++i) studentScores[i + 1] = sc.nextInt();
            for (int i = 0; i < M; ++i) {
                String operator = sc.next();
                int lhs = sc.nextInt();
                int rhs = sc.nextInt();
                if (operator.equals("Q")) {
                    int max = 0;
                    for (int start = Math.min(rhs, lhs); start <= Math.max(rhs, lhs); ++start) {
                        max = Math.max(max, studentScores[start]);
                    }
                    System.out.println(max);
                } else if (operator.equals("U")) {
                    studentScores[lhs] = rhs;
                }
            }
        }
    }
}
