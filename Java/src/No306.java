/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No306 {
    public boolean isAdditiveNumber(String num) {
        return backtrace(num, 0, 0, 0, 0, num.length());
    }

    private boolean backtrace(String s, int start, int count, long sum, long prev, int n) {
        if (start == n) return count >= 3;
        long value = 0;
        for (int i = start; i < n; ++i) {
            if (i > start && s.charAt(start) == '0') return false;
            value = value * 10 + s.charAt(i) - '0';
            if (count >= 2) {
                if (value < sum) continue;
                else if (value > sum) return false;
            }
            if (backtrace(s, i + 1, count + 1, prev + value, value, n)) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        No306 no306 = new No306();
        System.out.println(no306.isAdditiveNumber("199100199"));
    }
}
