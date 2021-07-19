/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.HashMap;
import java.util.Map;

public class No16dot02 {
    static class WordsFrequency {
        private Map<String, Integer> cnt = new HashMap<>();

        public WordsFrequency(String[] book) {
            for (String word : book) cnt.merge(word, 1, Integer::sum);
        }

        public int get(String word) {
            return cnt.getOrDefault(word, 0);
        }
    }
}
