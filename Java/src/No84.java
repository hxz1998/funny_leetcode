/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No84 {
    public int largestRectangleArea(int[] heights) {
        int size = heights.length;
        int[] left = new int[size];
        int[] right = new int[size];

        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < size; ++i) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) stack.pop();
            left[i] = (stack.isEmpty() ? -1 : stack.peek());
            stack.push(i);
        }

        stack.clear();
        for (int i = size - 1; i >= 0; --i) {
            while (!stack.empty() && heights[stack.peek()] >= heights[i]) stack.pop();
            right[i] = (stack.isEmpty() ? size : stack.peek());
            stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < size; ++i) ans = Math.max(ans, (right[i] - left[i] - 1) * heights[i]);
        return ans;
    }

    public static void main(String[] args) {
        No84 no84 = new No84();
        int[] heights = new int[]{2, 1, 5, 6, 2, 3};
        System.out.println(no84.largestRectangleArea(heights));
    }
}
