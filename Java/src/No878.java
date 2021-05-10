/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No878 {
    public int nthMagicalNumber(int n, int a, int b) {
        int lcm = a * b / (a < b ? gcd(b, a) : gcd(a, b));
        int mod = 1_000_000_007;
        long left = 0, right = Long.MAX_VALUE;
        while (left < right) {
            long mid = left + (right - left) / 2;
            long count = mid / a + mid / b - mid / lcm;
            if (count <= n) left = mid;
            else right = mid - 1;
        }
        return (int) left;
    }

    private int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    public static void main(String[] args) {
        No878 no878 = new No878();
        System.out.println(no878.gcd(6, 9));
    }
}
