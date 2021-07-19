/*
 * Copyright (c) 7/18/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No16dot05 {
    public int trailingZeroes(int n) {
        int cnt = 0;
        for (long num = 5; n / num > 0; num *= 5) {
            cnt += n / num;
        }
        return cnt;
    }

    public static void main(String[] args) {
        No16dot05 no16dot05 = new No16dot05();
        System.out.println(no16dot05.trailingZeroes(1808548329));
    }
}
