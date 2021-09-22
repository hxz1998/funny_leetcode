/*
 * Copyright (c) 9/14/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.List;

public class No524 {
    public String findLongestWord(String s, List<String> dictionary) {
        String ret = "";
        for (String word : dictionary) {
            int i = 0, j = 0;
            while (i < s.length() && j < word.length()) {
                if (word.charAt(j) == s.charAt(i)) ++i;
                j++;
            }
            if (i == s.length()) {
                if (word.length() > ret.length() || (word.length() == ret.length() && word.compareTo(ret) < 0))
                    ret = word;
            }
        }
        return ret;
    }
}
