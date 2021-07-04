/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class No451 {
    public String frequencySort(String s) {
        Map<Character, Integer> count = new HashMap<>();
        for (char c : s.toCharArray()) count.put(c, count.getOrDefault(c, 0) + 1);
        int n = count.size();
        Map.Entry<Character, Integer>[] entries = new Map.Entry[n];
        int idx = 0;
        for (Map.Entry<Character, Integer> entry : count.entrySet()) entries[idx++] = entry;
        Arrays.sort(entries, (o1, o2) -> o2.getValue() - o1.getValue());
        StringBuilder builder = new StringBuilder();
        for (Map.Entry<Character, Integer> entry : entries) {
            for (int i = 0; i < entry.getValue(); ++i) {
                builder.append(entry.getKey());
            }
        }
        return builder.toString();
    }

    public static void main(String[] args) {
        No451 no451 = new No451();
        System.out.println(no451.frequencySort("tree"));
    }
}
