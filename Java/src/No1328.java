/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1328 {
    public String breakPalindrome(String palindrome) {
        if (palindrome.length() == 1) return "";

        char[] cs = palindrome.toCharArray();

        int cnt = 0;
        for (char c : cs) if (c == 'a') cnt++;
        if (cnt == cs.length || cnt == cs.length - 1) {
            cs[cs.length - 1] = 'b';
            return new String(cs);
        }
        for (int i = 0; i < cs.length; ++i) {
            if (cs[i] != 'a') {
                cs[i] = 'a';
                return new String(cs);
            }
        }
        return "";
    }
}
