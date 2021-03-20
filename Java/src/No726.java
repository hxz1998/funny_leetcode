/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class No726 {
    private int i = 0;

    public String countOfAtoms(String formula) {
        StringBuilder ans = new StringBuilder();
        Map<String, Integer> mapper = new HashMap<>();
        Map<String, Integer> count = parse(formula);
        for (String name : count.keySet()) {
            ans.append(name);
            int multi = count.get(name);
            if (multi > 1) ans.append("" + multi);
        }
        return ans.toString();
    }

    private Map<String, Integer> parse(String formula) {
        int size = formula.length();
        Map<String, Integer> count = new TreeMap<>();
        while (i < size && formula.charAt(i) != ')') {
            if (formula.charAt(i) == '(') {
                ++i;
                for (Map.Entry<String, Integer> entry : parse(formula).entrySet()) {
                    count.put(entry.getKey(), count.getOrDefault(entry.getKey(), 0) + entry.getValue());
                }
            } else {
                int iStart = i++;
                while (i < size && Character.isLowerCase(formula.charAt(i))) i++;
                String name = formula.substring(iStart, i);
                iStart = i;
                while (i < size && Character.isDigit(formula.charAt(i))) i++;
                int multiplicity = iStart < i ? Integer.parseInt(formula.substring(iStart, i)) : 1;
                count.put(name, count.getOrDefault(name, 0) + multiplicity);
            }
        }
        int iStart = ++i;
        while (i < size && Character.isDigit(formula.charAt(i))) ++i;
        if (iStart < i) {
            int multiplicity = Integer.parseInt(formula.substring(iStart, i));
            for (String key : count.keySet()) count.put(key, count.get(key) * multiplicity);
        }
        return count;
    }
}
