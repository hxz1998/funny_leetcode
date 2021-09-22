/*
 * Copyright (c) 9/11/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lccup2021fall;

import java.util.HashMap;
import java.util.Map;

public class No1 {
    public int minimumSwitchingTimes(int[][] source, int[][] target) {
        Map<Integer, Integer> mapper1 = new HashMap<>(), mapper2 = new HashMap<>();
        for (int i = 0; i < source.length; ++i) {
            for (int j = 0; j < source[0].length; ++j) {
                mapper1.put(source[i][j], mapper1.getOrDefault(source[i][j], 0) + 1);
                mapper2.put(target[i][j], mapper2.getOrDefault(target[i][j], 0) + 1);
            }
        }
        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : mapper1.entrySet()) {
            int value = mapper2.get(entry.getKey()) == null ? 0 : mapper2.get(entry.getKey());
            int remain = entry.getValue() >= value ? entry.getValue() - value : 0;
            entry.setValue(remain);
        }
        for (Map.Entry<Integer, Integer> entry : mapper1.entrySet()) ans += entry.getValue();
        return ans;
    }

    public static void main(String[] args) {

    }
}
