/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No1418 {
    public List<List<String>> displayTable(List<List<String>> orders) {
        // 记录菜的种类
        TreeSet<String> set = new TreeSet<>();
        // 映射用户的桌号到菜单的哈希表, 其中 value 保存的是 菜名-数量 表
        TreeMap<String, Map<String, Integer>> mapper = new TreeMap<>((Comparator.comparingInt(Integer::parseInt)));
        // 把订单逐个添加到哈希表, 菜名添加到集合中
        for (List<String> order : orders) {
            set.add(order.get(2));
            var cnt = mapper.getOrDefault(order.get(1), new TreeMap<>());
            cnt.put(order.get(2), cnt.getOrDefault(order.get(2), 0) + 1);
            mapper.put(order.get(1), cnt);
        }
        // 返回值
        List<List<String>> ans = new ArrayList<>();
        // 构造表头
        List<String> tableHead = new ArrayList<>();
        tableHead.add("Table");
        tableHead.addAll(set);
        ans.add(tableHead);
        // 逐个添加表的内容
        for (Map.Entry<String, Map<String, Integer>> entry : mapper.entrySet()) {
            List<String> list = new ArrayList<>();
            // 先添加桌号
            list.add(entry.getKey());
            for (String item : set) {
                // 如果其中某一个菜没有在订单表中找到, 那么就添加 0
                list.add(entry.getValue().getOrDefault(item, 0).toString());
            }
            ans.add(list);
        }
        return ans;
    }

    public static void main(String[] args) {

        String s = "abc";
        System.out.println(s.substring(0, s.length() - 1));

    }
}
