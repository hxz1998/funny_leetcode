/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1309 {
    public String freqAlphabets(String s) {
        StringBuilder builder = new StringBuilder();
        char[] cs = s.toCharArray();
        for (int idx = 0; idx < cs.length; ++idx) {
            if (cs[idx] == '0') {
                char c1 = builder.charAt(builder.length() - 1);
                builder.deleteCharAt(builder.length() - 1);
                int num1 = c1 - 'a' + 1;
                builder.append((char) (num1 * 10 + 'a' - 1));
                idx++;
            } else if (cs[idx] == '#') {
                char c1 = builder.charAt(builder.length() - 1);
                builder.deleteCharAt(builder.length() - 1);
                char c2 = builder.charAt(builder.length() - 1);
                builder.deleteCharAt(builder.length() - 1);
                int num1 = c2 - 'a' + 1;
                int num2 = c1 - 'a' + 1;
                builder.append((char) ('a' + num1 * 10 + num2 - 1));
            } else {
                builder.append((char) (cs[idx] - '1' + 'a'));
            }
        }
        return builder.toString();
    }

    public static void main(String[] args) {
        No1309 no1309 = new No1309();
        System.out.println(no1309.freqAlphabets("1326#"));
    }
}
