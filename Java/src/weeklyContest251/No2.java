/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest251;

public class No2 {
    public String maximumNumber(String num, int[] change) {
        char[] cs = num.toCharArray();
        for (int idx = 0; idx < cs.length; ++idx) {
            if (cs[idx] - '0' < change[cs[idx] - '0']) {
                while (idx < cs.length && cs[idx] - '0' <= change[cs[idx] - '0']) {
                    cs[idx] = (char) ('0' + change[cs[idx] - '0']);
                    idx++;
                }
                return new String(cs);
            }
        }
        return new String(cs);
    }
}
