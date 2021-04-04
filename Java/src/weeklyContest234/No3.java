/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest234;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class No3 {
    private Map<String, String> mapper;

    public String evaluate(String s, List<List<String>> knowledge) {
        mapper = new HashMap<>();
        // 首先使用哈希表建立键值映射表
        for (List<String> item : knowledge) mapper.put(item.get(0), item.get(1));
        // builder 用来对括号内的字符进行保存
        StringBuilder builder = new StringBuilder();
        // ans 用来构建返回值
        StringBuilder ans = new StringBuilder();
        // flag 用来记录当前是不是在括号内
        boolean flag = false;
        for (char c : s.toCharArray()) {
            // 如果遇到了右括号，就需要把括号内的东西进行处理
            if (c == ')') {
                // 同时设置标志位为 false，从括号内出来了
                flag = false;
                String key = builder.toString();
                // 清空缓存
                builder = new StringBuilder();
                // 拼凑结果
                ans.append(mapper.getOrDefault(key, "?"));
            } else if (c == '(') {
                // 标记进来了括号内
                flag = true;
            } else if (flag) builder.append(c); // 如果在括号内，就往缓存里放，否则就进行下面的，直接往返回值里放
            else ans.append(c);
        }
        return ans.toString();
    }

    public static void main(String[] args) {
        No3 no3 = new No3();
        List<String> list1 = new ArrayList<>(), list2 = new ArrayList<>();
        list1.add("name");
        list1.add("bob");
        list2.add("age");
        list2.add("two");
        List<List<String>> list = new ArrayList<>();
        list.add(list1);
        list.add(list2);
        System.out.println("bobistwoyearsold".equals(no3.evaluate("(name)is(age)yearsold", list)));
    }
}
