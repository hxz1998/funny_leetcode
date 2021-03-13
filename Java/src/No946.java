/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No946 {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        int size = pushed.length;
        // 对 pushed 中的每一个元素进行遍历（直接入栈）
        // ip 是 popped 的游标
        for (int i = 0, ip = 0; i < size; ++i) {
            stack.push(pushed[i]);
            // 然后弹出来所有符合 popped 序列的栈内元素，记得把 popped 的游标右移
            while (!stack.empty() && popped[ip] == stack.peek()) {
                stack.pop();
                ++ip;
            }
        }
        // 最后检查栈是不是空的，空了说明原来的序列可进行操作
        return stack.empty();
    }

    public static void main(String[] args) {
        int[] pushed = new int[]{1, 2, 3, 4, 5};
        int[] popped = new int[]{4, 5, 3, 2, 1};
        No946 no946 = new No946();
        System.out.println(no946.validateStackSequences(pushed, popped));
    }
}
