/*
 * Copyright (c) 8/6/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class No1249 {
    public String minRemoveToMakeValid(String s) {
        // 用来拼接最后的返回值
        StringBuilder builder = new StringBuilder();
        // 记录左括号出现的位置
        LinkedList<Integer> leftParenthesisCount = new LinkedList<>();
        for (int idx = 0; idx < s.length(); ++idx) {
            char c = s.charAt(idx);
            if (c == '(') {
                // 遇到左括号，直接放到 builder 中，并且记录在 builder 中出现的位置
                builder.append(c);
                leftParenthesisCount.add(builder.length() - 1);
            } else if (c == ')') {
                //遇到右括号，如果发现前面没有剩余的空闲左括号，就直接跳过，否则就删掉一个左括号位置记录
                if (leftParenthesisCount.size() == 0) continue;
                builder.append(c);
                leftParenthesisCount.removeLast();
            } else builder.append(c);   // 遇到其他字符，直接拼接
        }
        // 把剩余的无用左括号全部清空
        while (!leftParenthesisCount.isEmpty()) {
            builder.deleteCharAt(leftParenthesisCount.removeLast());
        }
        return builder.toString();
    }

    public static void main(String[] args) {
        No1249 no1249 = new No1249();
        System.out.println(no1249.minRemoveToMakeValid("lee(t(c)o)de)"));
        System.out.println(no1249.minRemoveToMakeValid("))(("));
    }
}
