/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class No30 {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) return res;
        HashMap<String, Integer> mapper = new HashMap<>();
        for (String item : words) mapper.put(item, mapper.getOrDefault(item, 0) + 1);
        int oneWordLength = words[0].length();
        int wordsLength = words.length * oneWordLength;
        for (int i = 0; i < s.length() - wordsLength + 1; ++i) {
            String tmp = s.substring(i, i + wordsLength);
            HashMap<String, Integer> tmpMap = new HashMap<>();
            for (int j = 0; j < wordsLength; j += oneWordLength) {
                String string = tmp.substring(j, j + oneWordLength);
                tmpMap.put(string, tmpMap.getOrDefault(string, 0) + 1);
            }
            if (tmpMap.equals(mapper)) res.add(i);
        }
        return res;
    }

    public static void main(String[] args) {
        String[] words = {"foo", "bar"};
        No30 no30 = new No30();
        System.out.println(no30.findSubstring("barfoothefoobarman", words).toString());
    }
}
