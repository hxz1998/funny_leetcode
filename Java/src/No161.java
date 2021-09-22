/*
 * Copyright (c) 8/21/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No161 {
    public boolean isOneEditDistance(String s, String t) {
        if (s.length() == 0 && t.length() == 0 || Math.abs(s.length() - t.length()) >= 2) return false;
        // 确保 s 长度大于 t 长度
        if (s.length() < t.length()) return isOneEditDistance(t, s);
        if (s.length() == 1 && t.length() == 0) return true;
        int diff = 0;
        for (int i = 0, j = 0; i < s.length() && j < t.length(); ++i) {
            if (s.charAt(i) != t.charAt(j)) {
                if (diff >= 1) return false;
                if (s.length() == t.length()) {
                    diff++;
                    j++;
                } else diff++;
            } else {
                ++j;
            }
        }
        return diff == 1 || s.length() - t.length() == 1;
    }

    public static void main(String[] args) {
        No161 no161 = new No161();
        System.out.println(no161.isOneEditDistance("a", "ac"));
    }
}
