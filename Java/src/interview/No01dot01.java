/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;

public class No01dot01 {
    public boolean isUnique(String astr) {
        char[] cs = astr.toCharArray();
        Arrays.sort(cs);
        for (int i = 0; i < astr.length() - 1; ++i) if (cs[i] == cs[i + 1]) return false;
        return true;
    }
}
