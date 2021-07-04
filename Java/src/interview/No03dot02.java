/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Stack;

public class No03dot02 {
    static class MinStack {

        private Stack<Integer> data;
        private Stack<Integer> minData;

        public MinStack() {
            data = new Stack<>();
            minData = new Stack<>();
        }

        public void push(int x) {
            data.push(x);
            if (minData.isEmpty() || x <= minData.peek()) minData.push(x);
        }

        public void pop() {
            int value = data.pop();
            if (value <= minData.peek()) minData.pop();
        }

        public int top() {
            return data.peek();
        }

        public int getMin() {
            return minData.peek();
        }
    }
}
