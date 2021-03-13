/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No1130 {
    public int mctFromLeafValues(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        stack.push(Integer.MAX_VALUE);
        int ans = 0;
        for (int i = 0; i < arr.length; ++i) {
            while (arr[i] >= stack.peek()) ans += stack.pop() * Math.min(stack.peek(), arr[i]);
            stack.push(arr[i]);
        }
        while (stack.size() > 2) ans += stack.pop() * stack.peek();
        return ans;
    }
}
