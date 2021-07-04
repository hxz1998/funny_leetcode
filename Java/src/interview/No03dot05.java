/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Stack;

public class No03dot05 {
    static class SortedStack {
        private Stack<Integer> data;
        private Stack<Integer> buffer;

        public SortedStack() {
            data = new Stack<>();
            buffer = new Stack<>();
        }

        public void push(int val) {
            if (!data.isEmpty() && data.peek() > val) {
                data.push(val);
            } else {
                while (!data.isEmpty() && data.peek() <= val) buffer.push(data.pop());
                data.push(val);
                while (!buffer.isEmpty()) data.push(buffer.pop());
            }
        }

        public void pop() {
            if (data.isEmpty()) return;
            data.pop();
        }

        public int peek() {
            if (data.isEmpty()) return -1;
            return data.peek();
        }

        public boolean isEmpty() {
            return data.isEmpty();
        }
    }

    public static void main(String[] args) {
        SortedStack stack = new SortedStack();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.peek());
        stack.pop();
        System.out.println(stack.peek());
    }
}
