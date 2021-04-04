/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No591 {
    private Stack<String> stack = new Stack<>();
    boolean containTag = false;

    public boolean isValid(String code) {
        if (!code.startsWith("<") || !code.endsWith(">")) return false;
        for (int i = 0; i < code.length(); ++i) {
            boolean end = false;
            int closeIndex;
            if (stack.isEmpty() && containTag) return false;

        }
        return false;
    }

    private boolean isValidTagName(String s, boolean ending) {
        if (s.length() < 1 || s.length() > 9) return false;
        for (char c : s.toCharArray()) if (!Character.isUpperCase(c)) return false;
        if (ending) {
            if (!stack.isEmpty() && stack.peek().equals(s)) stack.pop();
            else return false;
        } else {
            containTag = true;
            stack.push(s);
        }
        return true;
    }

    private boolean isValidCData(String s) {
        return s.indexOf("[CDATA[") == 0;
    }
}
