/*
 * Copyright (c) 8/8/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1137 {
    public int tribonacci(int n) {
        int first = 0, second = 1, third = 1;
        if (n == 0) return first;
        if (n == 1) return second;
        if (n == 2) return third;
        for (int i = 3; i <= n; ++i) {
            int t = first;
            first = second;
            second = third;
            third = first + second + t;
        }
        return third;
    }

    public static void main(String[] args) {
        No1137 no1137 = new No1137();
        System.out.println(no1137.tribonacci(4));
    }
}
