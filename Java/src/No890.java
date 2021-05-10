/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class No890 {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList<>();
        for (String item : words) {
            if (check(item, pattern)) ans.add(item);
        }
        return ans;
    }

    private boolean check(String src, String pattern) {
        Map<Character, Character> p2s = new HashMap<>();
        Map<Character, Character> s2p = new HashMap<>();
        for (int idx = 0; idx < src.length(); ++idx) {
            char s = src.charAt(idx);
            char p = pattern.charAt(idx);
            if (p2s.containsKey(p)) {
                if (p2s.get(p) != s) return false;
            } else p2s.put(p, s);
            if (s2p.containsKey(s)) {
                if (s2p.get(s) != p) return false;
            } else s2p.put(s, p);
        }
        return true;
    }

    public static void main(String[] args) {
        String[] words = {"ccc"};
        No890 no890 = new No890();
        System.out.println(no890.check(words[0], "abb"));
    }
}
