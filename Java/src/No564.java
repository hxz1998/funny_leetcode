/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No564 {
    public String nearestPalindromic(String n) {
        char[] cs = n.toCharArray();
        int size = n.length();
        int left = (size & 1) == 0 ? size / 2 - 1 : size / 2;
        int right = size / 2;
        while (left >= 0 && right < size) {
            cs[right++] = cs[left--];
        }
        return new String(cs);
    }

    public static void main(String[] args) {
        No564 no564 = new No564();
        System.out.println(no564.nearestPalindromic("123"));
        System.out.println(no564.nearestPalindromic("1"));
    }
}
