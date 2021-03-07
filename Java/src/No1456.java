/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashSet;
import java.util.Set;

public class No1456 {
    public int maxVowels(String s, int k) {
        char[] c = s.toCharArray();
        Set<Character> set = new HashSet<>();
        // 元音字符表
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        int ans = 0;
        // 首先检查第一个窗口，看看里面有多少个
        for (int i = 0; i < k; ++i)
            if (set.contains(c[i])) {
                ans++;
            }
        // 然后从第一个位置开始滑动窗口，直到最后一个
        int window = ans;
        for (int left = 0, right = k; right < c.length; ++left, ++right) {
            if (set.contains(c[left])) window--;
            if (set.contains(c[right])) window++;
            ans = Math.max(ans, window);
        }
        return ans;
    }

    public static void main(String[] args) {
        No1456 no1456 = new No1456();
        System.out.println(no1456.maxVowels("leetcode", 3));
        System.out.println(no1456.maxVowels("rhythms", 4));
    }
}
