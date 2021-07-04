/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No03dot01 {
    static class TripleInOne {
        int[] data;
        int ptr1, ptr2, ptr3;
        int stackSize;

        public TripleInOne(int stackSize) {
            this.stackSize = stackSize;
            data = new int[stackSize * 3];
            ptr1 = 0;
            ptr2 = stackSize;
            ptr3 = stackSize * 2;
        }

        public void push(int stackNum, int value) {
            if (stackNum == 0) {
                if (ptr1 < stackSize) data[ptr1++] = value;
            } else if (stackNum == 1) {
                if (ptr2 < stackSize * 2) data[ptr2++] = value;
            } else {
                if (ptr3 < 3 * stackSize) data[ptr3++] = value;
            }
        }

        public int pop(int stackNum) {
            if (stackNum == 0) {
                if (isEmpty(stackNum)) return -1;
                else return data[--ptr1];
            } else if (stackNum == 1) {
                if (isEmpty(stackNum)) return -1;
                else return data[--ptr2];
            } else {
                if (isEmpty(stackNum)) return -1;
                else return data[--ptr3];
            }
        }

        public int peek(int stackNum) {
            if (stackNum == 0) return isEmpty(stackNum) ? -1 : data[ptr1 - 1];
            else if (stackNum == 1) return isEmpty(stackNum) ? -1 : data[ptr2 - 1];
            else return isEmpty(stackNum) ? -1 : data[ptr3 - 1];
        }

        public boolean isEmpty(int stackNum) {
            if (stackNum == 0) return ptr1 == 0;
            else if (stackNum == 1) return ptr2 == stackSize;
            else return ptr3 == stackSize * 2;
        }
    }
}
