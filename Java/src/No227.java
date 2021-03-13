/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Deque;
import java.util.LinkedList;

public class No227 {
    public int calculate(String s) {
        // ans 用来返回计算结果，n 用来把 "123" 转换成 123
        int ans = 0, n = 0;
        Deque<Integer> stack = new LinkedList<>();
        // 记录当前计算符号状态
        char sign = '+';
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            // 遇到字符数了，把字符转成数字
            if (Character.isDigit(c)) n = n * 10 + c - '0';
            // 如果遇到有效符号 +-*/ ，那么就执行计算
            // 需要加上 i == s.length() - 1 ，来确保最后一个数字也能参与计算
            if (c < '0' && c != ' ' || i == s.length() - 1) {
                switch (sign) {
                    case '+':
                        stack.addLast(n);   // 是加号状态，就直接把数字放进来
                        break;
                    case '-':
                        stack.addLast(-n);  // 负号状态，就放进来一个负的数字
                        break;
                    case '*':
                        stack.addLast(stack.pollLast() * n);    // 先把栈顶元素取出来，把栈顶元素和当前元素相乘后，放进栈中
                        break;
                    case '/':
                        stack.addLast(stack.pollLast() / n);    // 同样把栈顶元素取出来，然后相除后放进栈中
                        break;
                }
                sign = s.charAt(i); // 更新符号状态
                n = 0;  // 清空缓存数据
            }
        }
        // 把栈中的元素挨个加起来
        while (!stack.isEmpty()) ans += stack.pollLast();
        return ans;
    }

    public static void main(String[] args) {
        String s = "3+2*2";
        System.out.println(new No227().calculate(s));
        System.out.println(new No227().calculate("1+2*5/3+6/4*2"));
    }
}
