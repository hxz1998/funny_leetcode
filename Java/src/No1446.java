/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1446 {
    public int maxPower(String s) {
        int ans = 0, count = 1;
        char prev = s.charAt(0);
        char[] cs = s.toCharArray();
        for (int i = 1; i < cs.length; ++i) {
            if (cs[i] != prev) {
                ans = Math.max(count, ans);
                prev = cs[i];
                count = 1;
            } else {
                count++;
            }
        }
        return ans;
    }
}
