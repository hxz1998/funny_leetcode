/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No1023 {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> ans = new ArrayList<>();
        for (String item : queries) {
            if (check(item, pattern)) ans.add(true);
            else ans.add(false);
        }
        return ans;
    }

    private boolean check(String item, String pattern) {
        int idx = 0;
        int i = 0;
        for (; i < item.length(); ++i) {
            if (idx < pattern.length() && pattern.charAt(idx) == item.charAt(i)) idx++;
            else if (Character.isUpperCase(item.charAt(i))) return false;
        }
        return idx == pattern.length() && i == item.length();
    }
}
