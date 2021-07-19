/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No12 {
    public String intToRoman(int num) {
        int[] numbers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < numbers.length; ++i) {
            while (num >= numbers[i]) {
                num -= numbers[i];
                builder.append(symbols[i]);
            }
        }
        return builder.toString();
    }

    public static class No231 {
        public boolean isPowerOfTwo(int n) {
            int num = 0;
            while (num < 31) {
                if (n == (1 << num)) return true;
                num++;
            }
            return false;
        }
    }
}
