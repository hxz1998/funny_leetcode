/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

public class No1106 {
    public boolean parseBoolExpr(String expression) {
        Deque<Character> stack = new ArrayDeque<>();
        for (char c : expression.toCharArray()) {
            if (c == ',') continue;
            if (c != ')') stack.addLast(c);
            else {
                Deque<Character> buffer = new ArrayDeque<>();
                while (stack.peekLast() != '(') buffer.push(stack.pollLast());
                stack.pollLast();
                char ret = helper(buffer, stack.pollLast());
                stack.offerLast(ret);
            }
        }
        return stack.peek() == 't';
    }

    private char helper(Deque<Character> buffer, char operator) {
        if (operator == '!') return buffer.pollLast() == 't' ? 'f' : 't';
        if (operator == '&') {
            while (!buffer.isEmpty()) {
                if (buffer.pollLast() == 'f') return 'f';
            }
            return 't';
        }
        if (operator == '|') {
            while (!buffer.isEmpty()) {
                if (buffer.pollLast() == 't') return 't';
            }
            return 'f';
        }
        return ' ';
    }

    public static void main(String[] args) {
        No1106 no1106 = new No1106();
        System.out.println(no1106.parseBoolExpr("!(f)"));
    }
}
