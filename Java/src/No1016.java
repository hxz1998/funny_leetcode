/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1016 {
    public boolean queryString(String S, int N) {
        for (int i = 1; i <= N; ++i) {
            if (!S.contains(helper(i))) return false;
        }
        return true;
    }

    private String helper(int num) {
        StringBuilder builder = new StringBuilder();
        while (num > 0) {
            builder.append((num & 1) == 1 ? 1 : 0);
            num >>= 1;
        }
        return builder.reverse().toString();
    }
}
