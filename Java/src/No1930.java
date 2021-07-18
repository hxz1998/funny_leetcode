/*
 * Copyright (c) 7/12/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashSet;
import java.util.Set;

public class No1930 {
    public int countPalindromicSubsequence(String s) {
        int n = s.length();
        char[] cs = s.toCharArray();
        int ans = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            int left = 0, right = n - 1;
            while (left < n && cs[left] != ch) left++;
            while (right >= 0 && cs[right] != ch) right--;
            if (right - left < 2) continue;
            Set<Character> set = new HashSet<>();
            for (int idx = left + 1; idx < right; ++idx) set.add(cs[idx]);
            ans += set.size();
        }
        return ans;
    }
}
