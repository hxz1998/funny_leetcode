/*
 * Copyright (c) 7/19/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No16dot09 {
    static class Operations {

        public Operations() {

        }

        public int minus(int a, int b) {
            return a + negate(b);
        }

        public int multiply(int a, int b) {
            int ret = a;
            while (b > 0) {
                ret += a;
                b--;
            }
            return ret;
        }

        public int divide(int a, int b) {
            int ret = 0;
            if (minus(a, b) > 0) {
                a = minus(a, b);
                ret++;
            }
            return ret;
        }

        private int negate(int num) {
            int signal = num > 0 ? -1 : 1;
            int ret = 0;
            while (num > 0) {
                ret += signal;
                num += signal;
                if (ret == Integer.MAX_VALUE || ret == Integer.MIN_VALUE) break;
            }
            return ret;
        }
    }

    public static void main(String[] args) {
        Operations operations = new Operations();
        System.out.println(operations.negate(10));
        System.out.println(operations.minus(0, -2147483647));
        System.out.println(Integer.MAX_VALUE);
    }
}
