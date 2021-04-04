/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest235;

public class No1 {
    public String truncateSentence(String s, int k) {
        String[] items = s.split(" ");
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < k; ++i) builder.append(items[i]).append(" ");
        return builder.toString().substring(0, builder.length() - 2);
    }
}
