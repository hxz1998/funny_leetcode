/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No781 {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> mapper = new HashMap<>();
        for (int num : answers) mapper.put(num, mapper.getOrDefault(num, 0) + 1);
        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : mapper.entrySet()) {
            int key = entry.getKey(), value = entry.getValue();
            ans += (value + key) / (key + 1) * (key + 1);
        }
        return ans;
    }
}
