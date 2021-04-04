/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest49;

import java.util.HashMap;
import java.util.Map;

public class No2 {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        if (sentence1.equals(sentence2)) return true;
        // 保证 s1 是最长的那个字符串数组
        if (sentence1.length() < sentence2.length()) return areSentencesSimilar(sentence2, sentence1);
        String[] s1 = sentence1.split(" ");
        String[] s2 = sentence2.split(" ");
        if (s2.length == 1) return s2[0].equals(s1[0]) || s2[0].equals(s1[s1.length - 1]);
        int idx = 0;
        while (idx < s2.length && s2[idx].equals(s1[idx])) idx++;
        if (idx == s2.length) return true;
        idx = s2.length - 1;
        int offset = s1.length - s2.length;
        while (idx >= 0 && s2[idx].equals(s1[offset + idx])) --idx;
        if (idx == -1) return true;

        // 检查是否是夹在中间
        int l1 = 0, l2 = 0, r1 = s1.length - 1, r2 = s2.length - 1;
        while (l2 <= r2 && s1[l1].equals(s2[l2])) {
            l1++;
            l2++;
        }
        while (r2 >= 0 && s1[r1].equals(s2[r2])) {
            r1--;
            r2--;
        }
        return r2 == r1;
    }
}
