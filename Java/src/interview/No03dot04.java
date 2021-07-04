/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Stack;

public class No03dot04 {
    static class MyQueue {
        Stack<Integer> data;
        Stack<Integer> buffer;

        public MyQueue() {
            data = new Stack<>();
            buffer = new Stack<>();
        }

        public void push(int x) {
            data.push(x);
        }

        public int pop() {
            while (!data.isEmpty()) buffer.push(data.pop());
            int value = buffer.pop();
            while (!buffer.isEmpty()) data.push(buffer.pop());
            return value;
        }

        public int peek() {
            while (!data.isEmpty()) buffer.push(data.pop());
            int value = buffer.peek();
            while (!buffer.isEmpty()) data.push(buffer.pop());
            return value;
        }

        public boolean empty() {
            return data.isEmpty();
        }
    }
}
