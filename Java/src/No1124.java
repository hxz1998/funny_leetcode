/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No1124 {
    public int longestWPI(int[] hours) {
        int size = hours.length;
        int[] tired = new int[size + 1];
        tired[0] = 0;
        // 构造前缀和
        for (int i = 0; i < size; ++i) tired[i + 1] = tired[i] + (hours[i] > 8 ? 1 : -1);
        // 构造单调栈
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < size; ++i) {
            if (stack.isEmpty() || tired[i] < tired[stack.peek()]) stack.push(i);
        }

        // 从后往前寻找最长的上坡路
        int ans = 0;
        for (int i = size; i > 0; --i) {
            while (!stack.isEmpty() && tired[i] > tired[stack.peek()]) ans = Math.max(ans, i - stack.pop());
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] hours = new int[]{9, 9, 6, 0, 6, 6, 9};
        No1124 no1124 = new No1124();
        System.out.println(no1124.longestWPI(hours));
    }
}
