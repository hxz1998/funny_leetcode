/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No340 {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character, Integer> cnt = new HashMap<>();
        int left = 0, right = 0, n = s.length();
        int ans = 0;
        while (right < n) {
            while (right < n && cnt.size() <= k) {
                cnt.put(s.charAt(right), cnt.getOrDefault(s.charAt(right), 0) + 1);
                right++;
                if (cnt.size() <= k) ans = Math.max(ans, right - left);
            }
            while (cnt.size() > k) {
                char c = s.charAt(left);
                cnt.put(c, cnt.get(c) - 1);
                if (cnt.get(c) == 0) cnt.remove(c);
                left++;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        No340 no340 = new No340();
        System.out.println(no340.lengthOfLongestSubstringKDistinct("eceba", 2));
    }
}
