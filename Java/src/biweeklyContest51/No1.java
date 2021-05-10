/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest51;

public class No1 {
    public String replaceDigits(String s) {
        char[] cs = s.toCharArray();
        for (int i = 1; i < s.length(); i += 2) {
            cs[i] = (char) (cs[i - 1] + (cs[i] - '0'));
        }
        return new String(cs);
    }
}
