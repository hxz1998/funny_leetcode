/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class No1408 {
    public List<String> stringMatching(String[] words) {
        Arrays.sort(words, Comparator.comparingInt(String::length));
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < words.length; ++i) {
            for (int j = 0; j < words.length; ++j) {
                if (i == j) continue;
                if (words[j].contains(words[i])) ans.add(words[i]);
            }
        }
        return ans;
    }
}
