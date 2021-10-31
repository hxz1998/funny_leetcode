/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1209 {
    public String removeDuplicates(String s, int k) {
        StringBuilder builder = new StringBuilder(s);
        int n = s.length();
        int[] cnt = new int[n];
        for (int i = 0; i < builder.length(); ++i) {
            if (i == 0 || builder.charAt(i) != builder.charAt(i - 1)) cnt[i] = 1;
            else {
                cnt[i] = cnt[i - 1] + 1;
                if (cnt[i] == k) {
                    builder.delete(i - k + 1, i + 1);
                    i -= k;
                }
            }
        }
        return builder.toString();
    }

    public static void main(String[] args) {
        No1209 no1209 = new No1209();
        System.out.println(no1209.removeDuplicates("deeedbbcccbdaa", 3));
    }


}

