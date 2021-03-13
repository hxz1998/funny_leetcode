/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1021 {
    public String removeOuterParentheses(String S) {
        StringBuilder stringBuilder = new StringBuilder();
        int level = 0;
        for (char c : S.toCharArray()) {
            if (c == ')') --level;
            if (level >= 1) stringBuilder.append(c);
            if (c == '(') ++level;
        }
        return stringBuilder.toString();
    }
}
