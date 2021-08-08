/*
 * Copyright (c) 8/7/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest58;

public class No1 {
    public String makeFancyString(String s) {
        StringBuilder builder = new StringBuilder();
        builder.append(s.charAt(0));
        int cnt = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) == s.charAt(i - 1)) cnt++;
            else cnt = 1;
            if (cnt > 2) continue;
            else builder.append(s.charAt(i));
        }
        return builder.toString();
    }
}
