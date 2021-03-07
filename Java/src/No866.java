/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No866 {
    public int primePalindrome(int N) {
        while (true) {
            if (isReverse(N) && isPrime(N)) return N;
            N++;
            if (N > 10_000_000 && N < 100_000_000) N = 100_000_000;
        }
    }

    // 判断是不是回文数
    private boolean isReverse(int num) {
        String sNum = Integer.toString(num);
        String revSNum = new StringBuilder(sNum).reverse().toString();
        return Integer.parseInt(revSNum) == num;
    }

    // 检查一个数是不是素数
    private boolean isPrime(int num) {
        if (num < 2) return false;
        int r = (int) Math.sqrt(num);
        for (int i = 2; i <= r; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(new No866().primePalindrome(6));
        System.out.println(new No866().primePalindrome(8));
        System.out.println(new No866().primePalindrome(13));
    }
}
