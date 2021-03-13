/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No1003 {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            // 如果是 a 的话，直接入栈
            if (c == 'a') stack.push(c);
            // 如果是 b ，看看栈空不空，
            // 如果空了，那么就说明有一个地方是 b 开头的，也就是不合法的字符串
            // 如果不空，那么就直接入栈（逻辑中保证了前面一定是 a ）
            else if (c == 'b') {
                if (stack.empty()) return false;
                else stack.push(c);
            } else {
                // 遇到 c 的话，同样要检查当前栈内元素个数是否符合要求，如果小于2，说明前面不够 a 和 b
                // 也就直接返回 false
                if (stack.size() < 2) return false;
                // 把前两个弹出来，并检查是否符合要求
                char first = stack.pop();
                char secondary = stack.pop();
                if (first != 'b' || secondary != 'a') return false;
            }
        }
        // 最后检查栈空了没，没空就说明生下了某个 a 或者 ab
        return stack.empty();
    }

    public static void main(String[] args) {
        No1003 no1003 = new No1003();
        System.out.println(no1003.isValid("aabcbc"));
        System.out.println(no1003.isValid("cababc"));
        System.out.println(no1003.isValid("abcabcababcc"));
    }
}
