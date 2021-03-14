/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest232;

import java.util.ArrayList;

public class No1 {
    public boolean areAlmostEqual(String s1, String s2) {
        // list1 记录 s1 中不同的字符，list2 记录 s2 中不同的字符
        ArrayList<Character> list1 = new ArrayList<>(), list2 = new ArrayList<>();
        for (int i = 0; i < s1.length(); ++i)
            // 如果遇到不同，就记录下来
            if (s1.charAt(i) != s2.charAt(i)) {
                list1.add(s1.charAt(i));
                list2.add(s2.charAt(i));
            }
        // 首先检查两个字符是否一样的 size == 0，如果不是，那么检查是否有且只有两个字符不同 size == 2
        // 最后检查换位之后是否相同（ list1 的第一个和 list2 的第二个是否相同，list1的第二个 和 list2 的第一个是否相同）
        return list1.size() == 0 || list1.size() == 2 && list1.get(0) == list2.get(1) && list1.get(1) == list2.get(0);
    }
/*    public boolean areAlmostEqual(String s1, String s2) {
        if (s1.equals(s2)) return true;
        int size = s1.length();
        ArrayList<Integer> list = new ArrayList<>();
        char[] chars = s1.toCharArray();
        for (int i = 0; i < size; ++i) {
            if (chars[i] != s2.charAt(i)) {
                if (list.size() >= 2) return false;
                list.add(i);
            }
        }
        if (list.size() < 2) return false;
        char c = chars[list.get(0)];
        chars[list.get(0)] = chars[list.get(1)];
        chars[list.get(1)] = c;
        s1 = new String(chars);
        return s1.equals(s2);
    }*/

    public static void main(String[] args) {
        No1 no1 = new No1();
        System.out.println(no1.areAlmostEqual("abcd", "dcba"));
        System.out.println(no1.areAlmostEqual("kelb", "kelb"));
        System.out.println(no1.areAlmostEqual("bank", "kanb"));
        System.out.println(no1.areAlmostEqual("attack", "defend"));
    }
}
