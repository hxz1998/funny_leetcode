/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.HashMap;

public class No08dot08 {
    public String[] permutation(String S) {
        return helper(S).toArray(new String[0]);
    }

    private ArrayList<String> helper(String s) {
        ArrayList<String> result = new ArrayList<>();
        HashMap<Character, Integer> table = new HashMap<>();
        for (char c : s.toCharArray()) table.put(c, table.getOrDefault(c, 0) + 1);
        permutation(table, "", s.length(), result);
        return result;
    }

    private void permutation(HashMap<Character, Integer> table, String prefix, int remaining, ArrayList<String> result) {
        if (remaining == 0) {
            result.add(prefix);
            return;
        }
        for (char c : table.keySet()) {
            int count = table.get(c);
            if (count > 0) {
                table.put(c, count - 1);
                permutation(table, prefix + c, remaining - 1, result);
                table.put(c, count);
            }
        }
    }
}
