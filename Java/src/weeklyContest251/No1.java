/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest251;

public class No1 {
    public int getLucky(String s, int k) {
        StringBuilder builder = new StringBuilder();
        for (char c : s.toCharArray()) builder.append(c - 'a' + 1);
        int ans = 0;
        s = builder.toString();
        while (k-- > 0) {
            ans = 0;
            for (char c : s.toCharArray()) {
                ans += c - '0';
            }
            s = String.valueOf(ans);
        }
        return Integer.parseInt(s);
    }
}
