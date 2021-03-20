/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

class TimeMap {
    private Map<String, TreeMap<Integer, String>> data;

    /**
     * Initialize your data structure here.
     */
    public TimeMap() {
        data = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {
        // 检查一下有没有哈希表，如果有的话就直接添加，没有的话就需要 new 出来一个再添加 key-value
        TreeMap<Integer, String> mapper = data.getOrDefault(key,
                // 嵌套哈希表需要定义比较函数 Comparator ，然后按照从大到小排序
                new TreeMap<>((o1, o2) -> o2 - o1));
        mapper.put(timestamp, value);
        data.put(key, mapper);
    }

    public String get(String key, int timestamp) {
        TreeMap<Integer, String> mapper = data.get(key);
        if (mapper == null || mapper.isEmpty()) return "";
        else {
            // 从上到下挨个检查 time ，如果检查到的 time 小于timestamp了，那么就说明找到了，直接返回就好了
            for (int time : mapper.keySet()) if (time <= timestamp) return mapper.get(time);
        }
        return "";
    }
}

public class No981 {
    public static void main(String[] args) {
        TimeMap timeMap = new TimeMap();
        timeMap.set("foo", "bar", 1);
        timeMap.get("foo", 1);
        timeMap.get("foo", 3);
        timeMap.set("foo", "bar2", 4);
        timeMap.get("foo", 4);
        timeMap.get("foo", 5);
    }
}
