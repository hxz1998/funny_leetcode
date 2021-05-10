/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.List;

public class No1773 {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int idx = ruleKey.equals("type") ? 0 : ruleKey.equals("color") ? 1 : 2;
        int ans = 0;
        for (List<String> item : items) if (item.get(idx).equals(ruleValue)) ++ans;
        return ans;
    }
}
