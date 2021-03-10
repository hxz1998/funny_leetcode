/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Deque;
import java.util.LinkedList;

public class No224 {
    public int calculate(String s) {
        int size = s.length();
        Deque<Integer> operations = new LinkedList<>();
        operations.push(1);
        int sign = 1, res = 0, i = 0;
        while (i < size) {
            if (s.charAt(i) == ' ') ++i;
            else if (s.charAt(i) == '+') {
                sign = operations.peek();
                ++i;
            } else if (s.charAt(i) == '-') {
                sign = -operations.peek();
                ++i;
            } else if (s.charAt(i) == '(') {
                operations.push(sign);
                ++i;
            } else if (s.charAt(i) == ')') {
                operations.pop();
                ++i;
            } else {
                long num = 0;
                while (i < size && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + s.charAt(i) - '0';
                    ++i;
                }
                res += sign * num;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(new No224().calculate("(1+(4+5+2)-3)+(6+8)"));
    }
}
