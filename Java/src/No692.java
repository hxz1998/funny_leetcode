/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No692 {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> counter = new HashMap<>();
        for (String word : words) {
            counter.put(word, counter.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<Map.Entry<String, Integer>> queue = new PriorityQueue<>((o1, o2) -> o2.getValue() - o1.getValue() == 0 ? o1.getKey().compareTo(o2.getKey()) : o2.getValue() - o1.getValue());
        for (Map.Entry<String, Integer> entry : counter.entrySet()) queue.offer(entry);
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < k; ++i) ans.add(queue.poll().getKey());
        return ans;
    }
}
