/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest57;

import java.util.HashSet;
import java.util.Set;

public class No1 {
    public boolean areOccurrencesEqual(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) cnt[c - 'a']++;
        Set<Integer> set = new HashSet<>();
        for (int num : cnt) if (num != 0) set.add(num);
        if (set.size() >= 2) return false;
        return true;
    }
}
