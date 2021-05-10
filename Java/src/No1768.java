/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1768 {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder builder = new StringBuilder();
        int idx1 = 0, idx2 = 0;
        while (idx1 < word1.length() || idx2 < word2.length()) {
            if (idx1 == word1.length()) {
                builder.append(word2.charAt(idx2++));
                continue;
            }
            if (idx2 == word2.length()) {
                builder.append(word1.charAt(idx1++));
                continue;
            }

            if (idx1 <= idx2) builder.append(word1.charAt(idx1++));
            else builder.append(word2.charAt(idx2++));
        }
        return builder.toString();
    }
}
