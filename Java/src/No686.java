/*
 * Copyright (c) 12/22/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No686 {
    public int repeatedStringMatch(String a, String b) {
        if (b.length() == 0) return 0;
        else if (a.contains(b)) return 1;
        else {
            int times = (b.length() - 1) / a.length() + 1;
            StringBuilder builder = new StringBuilder();
            builder.append(a.repeat(times));
            if (builder.toString().contains(b)) return times;
            if (builder.append(a).toString().contains(b)) return times + 1;
            return -1;
        }
    }
}
