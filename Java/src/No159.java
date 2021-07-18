/*
 * Copyright (c) 7/15/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No159 {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int left = 0, right = 0, n = s.length();
        if (n < 3) return n;
        Map<Character, Integer> hashMap = new HashMap<>();
        int ans = 0;
        while (right < n) {
            if (hashMap.size() < 3) hashMap.put(s.charAt(right), right++);
            if (hashMap.size() == 3) {
                int delIndex = Collections.min(hashMap.values());
                hashMap.remove(s.charAt(delIndex));
                left = delIndex + 1;
            }
            ans = Math.max(ans, right - left);
        }
        return ans;
    }

    public static void main(String[] args) {
        No159 no159 = new No159();
        System.out.println(no159.lengthOfLongestSubstringTwoDistinct("eceba"));
        System.out.println(no159.lengthOfLongestSubstringTwoDistinct("ccaabbb"));
    }
}
