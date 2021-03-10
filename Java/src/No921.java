/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

public class No921 {
    public int minAddToMakeValid(String S) {
        if (S.length() == 0) return 0;
        Deque<Character> stack = new LinkedList<>();
        // 首先把第一个字符放进来
        stack.push(S.charAt(0));
        // 然后挨个遍历字符串中的字符
        for (int i = 1; i < S.length(); ++i) {
            char c = S.charAt(i);
            // 如果栈是空的，那么就直接放进来新的字符
            // 如果栈顶字符是 ( 而且当前字符是 ) 那么正好是一对儿，所以就把栈顶字符弹出来
            if (!stack.isEmpty() && c == ')' && stack.peekLast() == '(') {
                stack.pollLast();
            } else stack.addLast(c);
        }
        // 最后看看栈的大小，就是剩余下多少没配对
        return stack.size();
    }

    public static void main(String[] args) {
        No921 no921 = new No921();
        System.out.println(no921.minAddToMakeValid("((("));
        System.out.println(no921.minAddToMakeValid("()))(("));
        System.out.println(no921.minAddToMakeValid("()"));
        System.out.println(no921.minAddToMakeValid(")()"));
    }
}
