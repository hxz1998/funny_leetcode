/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest234;

import java.util.HashSet;
import java.util.Set;

public class No1 {
    // 之所以存 String 是因为有不符合要求的 Integer 类型，例如溢出
    private Set<String> set;

    public int numDifferentIntegers(String word) {
        set = new HashSet<>();
        // builder 用来保存产生的数字，为了方便就先叫他缓存吧
        StringBuilder builder = new StringBuilder();
        // 多加上这个 a ，是为了防止最后一个是数字，例如 aaa23 ，加上后会在下面程序中直接取到 23
        word += "a";
        // 然后逐个字符开始检查
        for (char c : word.toCharArray()) {
            // 如果字符是数字，那就好玩了
            if (Character.isDigit(c)) {
                // 首先看看是不是 0，如果是 0 而且缓存中是空的，那就直接放进来，对应的是 ab0ad 这样的序列
                if (c == '0' && builder.length() == 0) builder.append(c);
                // 如果不是 0，或缓存不空
                if (c != '0' || builder.length() != 0) {
                    // 如果缓存中只有一个 0，那么说明是前导0，删掉之前的就好了
                    if (builder.toString().equals("0")) builder = new StringBuilder();
                    builder.append(c);
                }
            } else if (builder.length() != 0) {
                // 来到这里是因为，一串数字解决完了，遇到了字母，就把取到的数字串存到集合中
                set.add(builder.toString());
                builder = new StringBuilder();
            }
        }
        // 最后检查集合大小
        return set.size();
    }

    public static void main(String[] args) {
        No1 no1 = new No1();
        System.out.println(no1.numDifferentIntegers("a123bc34d8ef34"));
        System.out.println(no1.numDifferentIntegers("a1b01c001"));
        System.out.println(no1.numDifferentIntegers("1"));
        System.out.println(no1.numDifferentIntegers("a"));
        System.out.println(no1.numDifferentIntegers("167278959591294"));
        System.out.println(no1.numDifferentIntegers("0a0"));
    }
}
