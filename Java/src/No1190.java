/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No1190 {
    public String reverseParentheses(String s) {
        // stack 用来保存整个字符串中最后的结果
        Stack<Character> stack = new Stack<>();
        // buffer 用来保存上一个 () 之间的内容
        Stack<Character> buffer = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c != ')') stack.push(c);
            else {
                // 调整 () 之间的顺序
                while (stack.peek() != '(') buffer.push(stack.pop());
                stack.pop();
                // 然后添加所有 buffer 里面的元素到 stack 里面
                stack.addAll(buffer);
                // 然后清空
                buffer.clear();
            }
        }
        // 构造返回值
        StringBuilder ans = new StringBuilder();
        for (char c : stack) ans.append(c);
        return ans.toString();
    }

    public static void main(String[] args) {
        No1190 no1190 = new No1190();
        System.out.println(no1190.reverseParentheses("(ed(et(oc))el)"));
    }
}
