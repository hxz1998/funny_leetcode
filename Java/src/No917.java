/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No917 {
    public String reverseOnlyLetters(String S) {
        if (S.length() == 0 || S.length() == 1) return S;
        int left = -1, right = S.length();
        char[] cs = S.toCharArray();
        while (true) {
            // 防止越界，所以对 left 和 right 都进行了边界检测
            // left 从左向右找到第一个字母
            while (!Character.isLetter(cs[++left])) if (left >= right || left >= S.length() - 1) break;
            // right 从右向左找到第一个字母
            while (!Character.isLetter(cs[--right])) if (right <= left) break;
            // 如果两个指针相遇了，那么就跳出去
            if (left >= right) break;
            // 否则就交换两个字符的位置
            char t = cs[left];
            cs[left] = cs[right];
            cs[right] = t;
        }
        return new String(cs);
    }

    public static void main(String[] args) {
        No917 no917 = new No917();
        System.out.println(no917.reverseOnlyLetters("Test1ng-Leet=code-Q!"));
        System.out.println(no917.reverseOnlyLetters("ab-cd"));
        System.out.println(no917.reverseOnlyLetters("7_28]"));
        System.out.println(no917.reverseOnlyLetters("abcd"));
        System.out.println(no917.reverseOnlyLetters("abc"));
    }
}
