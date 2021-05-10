/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No20 {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '{' || c == '(' || c == '[') stack.add(c);
            else {
                if (stack.isEmpty()) return false;
                char top = stack.pop();
                if (c == '}' && top != '{') return false;
                else if (c == ')' && top != '(') return false;
                else if (c == ']' && top != '[') return false;
            }
        }
        return stack.isEmpty();
    }
}
