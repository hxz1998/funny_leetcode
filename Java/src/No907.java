/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No907 {
    private final int MOD = 1_000_000_007;

    public int sumSubarrayMins(int[] arr) {
        Stack<RepeatInteger> stack = new Stack<>();
        int ans = 0, dot = 0;
        for (int j = 0; j < arr.length; ++j) {
            int count = 1;
            while (!stack.empty() && stack.peek().val >= arr[j]) {
                RepeatInteger node = stack.pop();
                count += node.count;
                dot -= node.val * node.count;
            }
            stack.push(new RepeatInteger(arr[j], count));
            dot += arr[j] * count;
            ans += dot;
            ans %= MOD;
        }
        return ans;
    }

    static class RepeatInteger {
        int val, count;

        RepeatInteger(int val, int count) {
            this.val = val;
            this.count = count;
        }
    }
}
