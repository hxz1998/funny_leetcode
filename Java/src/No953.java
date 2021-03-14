/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No953 {
    public boolean isAlienSorted(String[] words, String order) {
        int[] index = new int[26];
        for (int i = 0; i < order.length(); ++i) index[order.charAt(i) - 'a'] = i;

        for (int i = 0; i < words.length - 1; ++i) {
            // 两两比较，首先比较第一个不同字符，如果其中一个是另一个的前缀，那么就去判断下面的长度是否符合要求
            String word1 = words[i], word2 = words[i + 1];
            boolean cmp = true;
            for (int j = 0; j < Math.min(word1.length(), word2.length()) && cmp; j++) {
                if (word1.charAt(j) != word2.charAt(j)) {
                    if (index[word1.charAt(j) - 'a'] > index[word2.charAt(j) - 'a']) return false;
                    else cmp = false;
                }
            }
            // 然后再比较两者的字符长度是否小的在前
            if (cmp && word1.length() > word2.length()) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        String[] words = new String[]{"word", "world", "row"};
        No953 no953 = new No953();
        System.out.println(no953.isAlienSorted(words, "worldabcefghijkmnpqstuvxyz"));
        words = new String[]{"hello", "leetcode"};
        System.out.println(no953.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz"));
    }
}
