/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.List;

public class No1417 {
    public String reformat(String s) {
        int numberCount = 0, characterCount = 0;
        char[] cs = s.toCharArray();
        for (char value : cs) {
            if (Character.isDigit(value)) numberCount++;
            else characterCount++;
        }
        if (Math.abs(characterCount - numberCount) >= 2) return "";
        char[] ret = new char[cs.length];
        int numIdx = characterCount > numberCount ? 1 : 0, charIdx = 1 - numIdx;
        for (char c : cs) {
            if (Character.isDigit(c)) {
                ret[numIdx] = c;
                numIdx += 2;
            } else {
                ret[charIdx] = c;
                charIdx += 2;
            }
        }
        return new String(ret);
    }
}
