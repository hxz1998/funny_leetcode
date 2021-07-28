/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashSet;
import java.util.Set;

public class No1180 {
    public int countLetters(String s) {
        int ans = 0, cnt = 1, n = s.length();
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                cnt++;
            } else {
                ans += (cnt + 1) * cnt / 2;
                cnt = 1;
            }
        }
        return ans + (cnt + 1) * cnt / 2;
    }

    public static void main(String[] args) {
        String s = "aaaba";
        No1180 no1180 = new No1180();
        System.out.println(no1180.countLetters(s));
    }
}
