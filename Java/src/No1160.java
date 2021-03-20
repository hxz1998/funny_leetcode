/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No1160 {
    private Map<Character, Integer> charCounter;

    public int countCharacters(String[] words, String chars) {
        charCounter = counter(chars);
        int ans = 0;
        // 对每一个单词进行检查判断
        for (String word : words) {
            Map<Character, Integer> mapper = counter(word);
            // 先假设是可以拼成的
            boolean flag = true;
            for (char key : mapper.keySet()) {
                // 在检查过程中，如果在字符序列中没有找到单词中的某一个字符或者个数不够，那么就说明不行，标记为 false
                if (!charCounter.containsKey(key) || mapper.get(key) > charCounter.get(key)) {
                    flag = false;
                    break;
                }
            }
            // 如果可以拼成，那么就加上这个单词的长度
            if (flag) ans += word.length();
        }
        return ans;
    }

    /**
     * 统计字符串中每一个字符出现的次数
     * @param word 待统计的字符串
     * @return 返回一个哈希表，字符 - 次数
     */
    private Map<Character, Integer> counter(String word) {
        Map<Character, Integer> mapper = new HashMap<>();
        for (char c : word.toCharArray()) mapper.put(c, mapper.getOrDefault(c, 0) + 1);
        return mapper;
    }
}
