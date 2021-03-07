/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest47;

public class No2 {
    int max = (int) Math.pow(3, (int) (Math.log(0x7fffffff) / Math.log(3)));

    public boolean checkPowersOfThree(int n) {
        // 先判断是否是 3 的若干次方
        if (max % n == 0) return true;
        // 然后判断能否被 3 的若干次方减完
        int num = 1;
        while (num < n) num *= 3;
        num /= 3;
        while (n > 0) {
            n -= num;
            if (num == 0 && n != 0) return false;
            num /= 3;
            while (num > n) num /= 3;
        }
        return n == 0;
    }

    public static void main(String[] args) {
        No2 no2 = new No2();
        System.out.println(no2.checkPowersOfThree(12));
        System.out.println(no2.checkPowersOfThree(91));
        System.out.println(no2.checkPowersOfThree(21));
        System.out.println(no2.checkPowersOfThree(27));
    }
}
