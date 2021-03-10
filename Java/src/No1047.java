/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Iterator;
import java.util.Stack;

public class No1047 {
    public String removeDuplicates(String S) {
        // 如果就一个字符，那么不用检查了，直接返回。
        if (S.length() == 1) return S;
        StringBuilder ans = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        // 先转换成字符序列，然后方便挨个处理
        char[] chars = S.toCharArray();
        stack.push(chars[0]);
        // 如果栈顶字符和当前字符一样，那么就弹出去栈顶字符，同时跳过当前字符
        for (int i = 1; i < chars.length; ++i) {
            while (!stack.empty() && i < chars.length && stack.lastElement() == chars[i]) {
                stack.pop();    // 弹出栈顶字符
                i++;            // 跳过当前字符
            }
            // 检查一下是否到了序列末尾
            if (i >= chars.length) break;
            // 找到一个不重复的字符，放到栈中
            stack.push(chars[i]);
        }
        Iterator<Character> iter = stack.iterator();
        // 构建返回值
        while (iter.hasNext()) ans.append(iter.next());
        return ans.toString();
    }

    public static void main(String[] args) {
        No1047 no1047 = new No1047();
        System.out.println(no1047.removeDuplicates("abbaca"));
        System.out.println(no1047.removeDuplicates("aaaaaaaa"));
    }
}
