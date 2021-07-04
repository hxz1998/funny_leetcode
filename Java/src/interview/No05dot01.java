/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No05dot01 {
    public int insertBits(int N, int M, int i, int j) {
        // 先把相应的位置零
        int allOnes = ~0;
        int left = j == 31 ? 0 : (allOnes << (j + 1));
        int right = (1 << i) - 1;
        int mask = (left | right);
        N &= mask;
        M <<= i;
        return N | M;
    }

    public static void main(String[] args) {
        No05dot01 no05dot01 = new No05dot01();
        System.out.println((~0) << 2);
        System.out.println(no05dot01.insertBits(1143207437, 1017033, 11, 31));
    }
}
