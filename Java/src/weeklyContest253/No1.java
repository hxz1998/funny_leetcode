/*
 * Copyright (c) 8/8/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest253;

public class No1 {
    public boolean isPrefixString(String s, String[] words) {
        int n = words.length;
        for (int i = 0; i < n; ++i) {
            if (s.length() == 0) return true;
            if (s.startsWith(words[i])) {
                s = s.substring(words[i].length());
            } else return false;
        }
        return s.length() == 0;
    }

    public static void main(String[] args) {
        No1 no1 = new No1();
        String[] words = {"i", "love", "leetcode", "apples"};
        System.out.println(no1.isPrefixString("iloveleetcode", words));
    }
}
