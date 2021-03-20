/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No966 {
    Set<String> set;
    Map<String, String> wordsVow;
    Map<String, String> mapper;

    public String[] spellchecker(String[] wordlist, String[] queries) {
        // 对应原来的单词
        set = new HashSet<>();
        // 对应单词的小写形式
        mapper = new HashMap<>();
        // 记录忽略了元音之后的单词
        wordsVow = new HashMap<>();
        // 让小写形式当成
        for (String word : wordlist) {
            set.add(word);
            String wordLow = word.toLowerCase();
            mapper.putIfAbsent(wordLow, word);
            wordsVow.putIfAbsent(devowel(wordLow), word);
        }
        for (int i = 0; i < queries.length; ++i) {
            queries[i] = solve(queries[i]);
        }
        return queries;
    }

    private String solve(String item) {
        if (set.contains(item)) return item;
        if (mapper.containsKey(item.toLowerCase())) return mapper.get(item.toLowerCase());
        if (wordsVow.containsKey(devowel(item.toLowerCase()))) return wordsVow.get(devowel(item.toLowerCase()));
        return "";
    }

    private String devowel(String word) {
        StringBuilder sb = new StringBuilder();
        for (char c : word.toCharArray()) sb.append(isVowel(c) ? '*' : c);
        return sb.toString();
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public static void main(String[] args) {
        String[] wordList = {"KiTe", "kite", "hare", "Hare" };
        String[] queries = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto" };
        No966 no966 = new No966();
        System.out.println(Arrays.toString(no966.spellchecker(wordList, queries)));
        wordList = new String[]{"ae", "aa" };
        queries = new String[]{"UU" };
        System.out.println(Arrays.toString(no966.spellchecker(wordList, queries)));
    }
}
