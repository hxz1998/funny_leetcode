/*
 * Copyright (c) 7/13/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayDeque;
import java.util.Deque;

public class No16dot26 {
    public int calculate(String s) {
        Deque<Character> operator = new ArrayDeque<>();
        Deque<Integer> number = new ArrayDeque<>();
        int n = s.length();
        int idx = 0;
        while (idx < n) {
            if (Character.isDigit(s.charAt(idx))) {
                int buffer = 0;
                buffer += s.charAt(idx++) - '0';
                while (idx < n && Character.isDigit(s.charAt(idx))) {
                    buffer = buffer * 10 + s.charAt(idx) - '0';
                    ++idx;
                }
                number.add(buffer);
            } else if (s.charAt(idx) == '+' || s.charAt(idx) == '-' || s.charAt(idx) == '*' || s.charAt(idx) == '/') {
                // 如果当前运算符的优先级大于栈顶元素，那么就直接放进来，否则就先计算再放新的运算符
                while (!number.isEmpty() && !operator.isEmpty() && priority(operator.peekLast(), s.charAt(idx)))
                    calc(operator, number);
                operator.add(s.charAt(idx));
                ++idx;
            } else if (s.charAt(idx) == ' ') ++idx;
        }
        while (!operator.isEmpty()) calc(operator, number);
        return number.peek();
    }

    private void calc(Deque<Character> operator, Deque<Integer> number) {
        char opr = operator.pollLast();
        int num1 = number.pollLast(), num2 = number.pollLast();
        if (opr == '+') number.add(num1 + num2);
        else if (opr == '-') number.add(num2 - num1);
        else if (opr == '*') number.add(num1 * num2);
        else number.add(num2 / num1);
    }

    // 如果 top 优先级大于等于 curr 那么就返回 true
    private boolean priority(char top, char curr) {
        if (top == curr) return true;
        else if (top == '*' || top == '/') return true;
        else return (top == '+' || top == '-') && (curr == '+' || curr == '-');
    }

    public static void main(String[] args) {
        No16dot26 no16dot26 = new No16dot26();
        System.out.println(no16dot26.priority('*', '-'));
        System.out.println(no16dot26.priority('+', '*'));
        System.out.println(no16dot26.priority('*', '/'));
        System.out.println(no16dot26.priority('/', '-'));
        System.out.println(no16dot26.priority('*', '/'));
        System.out.println(no16dot26.calculate("3+2*2"));
        System.out.println(no16dot26.calculate("42"));
        System.out.println(no16dot26.calculate("1-1+1"));
        System.out.println(no16dot26.calculate("1+2*5/3+6/4*2"));
    }
}
