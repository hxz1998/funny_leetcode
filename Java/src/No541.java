/*
 * Copyright (c) 8/20/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No541 {
    private void reverse(char[] chars, int begin, int end) {
        while (begin < end) {
            char c = chars[begin];
            chars[begin] = chars[end];
            chars[end] = c;
            begin++;
            end--;
        }
    }

    public String reverseStr(String s, int k) {
        char[] chars = s.toCharArray();
        for (int iter = 0; iter < chars.length; iter += 2 * k) {
            int begin = iter;
            int end = Math.min(chars.length - 1, begin + k - 1);
            reverse(chars, begin, end);
        }
        return new String(chars);
    }
}
