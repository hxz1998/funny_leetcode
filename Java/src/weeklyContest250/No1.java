/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest250;

import java.util.HashSet;
import java.util.Set;

public class No1 {
    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> broken = new HashSet<>();
        for (char c : brokenLetters.toCharArray()) broken.add(c);
        String[] words = text.split(" ");
        int ans = 0;
        for (String word : words) {
            int idx = 0;
            for (; idx < word.length(); ++idx) {
                if (broken.contains(word.charAt(idx))) break;
            }
            if (idx == word.length()) ans++;
        }
        return ans;
    }
}
