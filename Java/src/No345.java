/*
 * Copyright (c) 8/19/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class No345 {
    public String reverseVowels(String s) {
        Set<Character> vowels = new HashSet<Character>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        char[] chars = s.toCharArray();
        int n = s.length(), left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !vowels.contains(chars[left])) left++;
            while (left < right && !vowels.contains(chars[right])) right--;
            if (left >= right) break;
            char t = chars[left];
            chars[left] = chars[right];
            chars[right] = t;
            left++;
            right--;
        }
        return new String(chars);
    }
}
