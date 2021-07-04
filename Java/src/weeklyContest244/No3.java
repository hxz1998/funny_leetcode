/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest244;

public class No3 {
    public int minFlips(String s) {
        int n = s.length();
        String temp = s + s;
        StringBuilder builderA = new StringBuilder();
        StringBuilder builderB = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            builderA.append("01");
            builderB.append("10");
        }
        int ans = n;
        int da = 0, db = 0;
        for (int i = 0; i < n * 2; ++i) {
            if (temp.charAt(i) != builderA.charAt(i)) da += 1;
            if (temp.charAt(i) != builderB.charAt(i)) db += 1;
            if (i >= n) {
                if (temp.charAt(i - n) != builderA.charAt(i - n)) da -= 1;
                if (temp.charAt(i - n) != builderB.charAt(i - n)) db -= 1;
            }
            if (i >= n - 1) ans = Math.min(ans, Math.min(da, db));
        }
        return ans;
    }

    public static void main(String[] args) {
        No3 no3 = new No3();
        System.out.println(no3.minFlips("111000"));
        System.out.println(no3.minFlips("01001001101"));
        System.out.println(no3.minFlips("10001100101000000"));
    }
}
