/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest48;

public class No1 {
    public int secondHighest(String s) {
        // 顾名思义，first 是用来记录第一个的，second 是用来记录第二个的
        int first = -1, second = -1;
        for (char c : s.toCharArray()) {
            // 如果 c 是一个数字，那么就进行检查处理
            if (Character.isDigit(c)) {
                // 首先字符转换成数字
                int num = c - '0';
                // 如果 first 还没有赋值呢，那么就直接赋值
                if (first == -1) first = num;
                // first 已经带值，而且 num 比 first 还大，那么就更新它们
                else if (num > first) {
                    second = first;
                    first = num;
                } else if (num < first && num > second)
                    // 如果介于两者中间，那么就只更新第二个值
                    second = num;
            }
        }
        return second;
    }

    public static void main(String[] args) {
        No1 no1 = new No1();
        System.out.println(no1.secondHighest("dfa12321afd"));
        System.out.println(no1.secondHighest("abc1111"));
        System.out.println(no1.secondHighest("ck077"));
        System.out.println(no1.secondHighest("sjhtz8344"));
    }
}
