/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest242;

public class No1 {
    public boolean checkZeroOnes(String s) {
        char[] cs = s.toCharArray();
        int oneCount = 0;
        int buf = 0;
        for (int i = 0; i < cs.length; ++i) {
            if (cs[i] == '1') buf++;
            else {
                oneCount = Math.max(oneCount, buf);
                buf = 0;
            }
        }
        oneCount = Math.max(oneCount, buf);
        int zeroCount = 0;
        buf = 0;
        for (int i = 0; i < cs.length; ++i) {
            if (cs[i] == '0') buf++;
            else {
                zeroCount = Math.max(zeroCount, buf);
                buf = 0;
            }
        }
        zeroCount = Math.max(zeroCount, buf);
        return oneCount > zeroCount;
    }

    public static void main(String[] args) {
        No1 no1 = new No1();
        System.out.println(no1.checkZeroOnes("111000"));
    }
}
