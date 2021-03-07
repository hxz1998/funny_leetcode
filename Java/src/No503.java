/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Stack;

public class No503 {
    public int[] nextGreaterElements(int[] nums) {
        int size = nums.length;
        int[] ret = new int[size];
        Arrays.fill(ret, -1);
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < size * 2 - 1; ++i) {
            while (!stack.empty() && (nums[stack.peek()] < nums[i % size]))
                ret[stack.pop()] = nums[i % size];
            stack.push(i % size);
        }
        return ret;
    }

    public static void main(String[] args) {
        No503 test = new No503();
        int[] nums = new int[]{1, 2, 3, 4, 3};
        System.out.println(Arrays.toString(test.nextGreaterElements(nums)));
    }
}
