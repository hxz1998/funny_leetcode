/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No1006 {
    public int clumsy(int N) {
        // 捏出来一个栈，用于存放过程中的中间结果
        Stack<Integer> stack = new Stack<>();
        // 首先定义初次运算方式为 * [0: *, 1: /, 2: +, 3: -]
        int operation = 0;
        stack.push(N);  // 然后把第一个操作数放进来
        // 只要操作数大于 0，就一直循环下去
        while (--N > 0) {
            // 如果是乘法，就把栈顶元素拿出来和当前元素相乘再放回去
            if (operation % 4 == 0) stack.push(stack.pop() * N);
            // 如果是除法，就把栈顶元素拿出来与当前元素相除再放回去，需要注意的是运算顺序
            else if (operation % 4 == 1) stack.push(stack.pop() / N);
            // 如果是加法，那么就直接放进来这个数
            else if (operation % 4 == 2) stack.push(N);
            // 如果是减法的话，当然直接放进来 它的负数 就好了
            else stack.push(-N);
            // 然后循环下一个操作
            operation = (operation + 1) % 4;
        }
        int ans = 0;
        // 把栈中的元素累加起来，就得到了最后的结果
        for (int num : stack) ans += num;
        return ans;
    }

    public static void main(String[] args) {
        No1006 no1006 = new No1006();
        System.out.println(no1006.clumsy(4));
        System.out.println(no1006.clumsy(10));
    }
}
