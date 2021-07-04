/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest246;

public class No1 {
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i >= 0; --i){
            if ((num.charAt(i) - '0') % 2 == 1) {
                StringBuilder builder = new StringBuilder();
                for (int j = 0; j <= i; ++j) builder.append(num.charAt(j));
                return builder.toString();
            }
        }
        return "";
    }

    public static void main(String[] args) {
        No1 no1 = new No1();
        System.out.println(no1.largestOddNumber("35427"));
        System.out.println(no1.largestOddNumber("4206"));
        System.out.println(no1.largestOddNumber("52"));
    }
}
