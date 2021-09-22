/*
 * Copyright (c) 8/26/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class No16dot20 {
    public List<String> getValidT9Words(String num, String[] words) {
        Map<Character, Integer> mapper = new HashMap<>();
        for (char c = 'a'; c <='z'; ++c) {
            if (c <= 'o') mapper.put(c, (c - 'a') / 3 + 2);
            else if (c == 'p' || c == 'q' || c == 'r' || c == 's') mapper.put(c, 7);
            else if (c == 't' || c == 'u' || c == 'v') mapper.put(c, 8);
            else mapper.put(c, 9);
        }
        List<String> ans = new ArrayList<>();
        for (String word : words) {
            StringBuilder builder = new StringBuilder();
            for (char c : word.toCharArray()) builder.append(mapper.get(c));
            if (builder.toString().equals(num)) ans.add(word);
        }
        return ans;
    }

    public static void main(String[] args) {
        No16dot20 no16dot20 = new No16dot20();
        System.out.println(no16dot20.getValidT9Words("8733", new String[]{"tree", "used"}));
    }
}
