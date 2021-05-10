/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1763 {
    public String longestNiceSubstring(String s) {
        int n = s.length();
        String ans = "";
        char[] cs = s.toCharArray();
        for (int i = 0; i < n; ++i) {
            int a = 0, b = 0;
            for (int j = i; j < n; ++j) {
                if (Character.isLowerCase(cs[j])) a |= 1 << (cs[j] - 'a');
                else b |= 1 << (cs[j] - 'A');
                if (a == b && j - i + 1 > ans.length()) ans = s.substring(i, j + 1);
            }
        }
        return ans;
    }
}
