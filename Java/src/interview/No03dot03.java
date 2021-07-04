/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

public class No03dot03 {
    static class StackOfPlates {
        private int size;
        private int idx;
        private List<Stack<Integer>> list;

        public StackOfPlates(int cap) {
            this.size = cap;
            idx = -1;
            list = new ArrayList<>();
        }

        public void push(int val) {
            if (size == 0) return;
            if (list.isEmpty() || idx == -1 || list.get(idx).size() >= size) {
                Stack<Integer> stack = new Stack<>();
                idx++;
                list.add(stack);
            }
            list.get(idx).add(val);
        }

        public int pop() {
            if (size == 0) return -1;
            return popAt(list.size() - 1);
        }

        public int popAt(int index) {
            if (size == 0) return -1;
            if (index > idx || list.isEmpty() || list.get(0).isEmpty()) return -1;
            int value = list.get(index).pop();
            if (list.get(index).isEmpty()) {
                list.remove(index);
                idx--;
            }
            return value;
        }
    }
}
