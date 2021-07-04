/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest52;

import java.util.Arrays;

public class No1 {
    public String sortSentence(String s) {
        String[] strings = s.split(" ");
        Arrays.sort(strings, (o1, o2) -> {
            return o1.charAt(o1.length() - 1) - o2.charAt(o2.length() - 1);
        });
        StringBuilder builder = new StringBuilder();
        for (String ss : strings) builder.append(ss, 0, ss.length() - 1).append(" ");
        return builder.substring(0, builder.length() - 1);
    }
}
