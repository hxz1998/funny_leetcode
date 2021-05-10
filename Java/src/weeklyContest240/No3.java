/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest240;

import java.util.Arrays;
import java.util.Stack;

public class No3 {
    private static final int MOD = 1_000_000_007;

    public int maxSumMinProduct(int[] nums) {
        int n = nums.length;
        int[] t = new int[n + 2];
        for (int i = 1; i <= n; ++i) t[i] = nums[i - 1];
        nums = t;

        int[] left = new int[n], right = new int[n];
        Stack<Integer> stack = new Stack<>();

        // 单调栈的构建过程！
        // 右边第一个小于 nums[i] 的位置
        for (int i = 0; i < n; ++i) {
            if (!stack.isEmpty() && nums[i] < nums[stack.peek()]) right[stack.pop()] = i;
            stack.push(i);
        }
        stack.clear();
        for (int i = n - 1; i >= 0; --i) {
            if (!stack.isEmpty() && nums[i] < nums[stack.peek()]) right[stack.pop()] = i;
            stack.push(i);
        }

        long[] pre = new long[n];
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {

        }

        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = Math.max(ans, nums[i] * (pre[right[i]] - pre[left[i]]));
        }
        return (int) ans % MOD;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 2};
        No3 no3 = new No3();
        System.out.println(no3.maxSumMinProduct(nums));
    }
}
