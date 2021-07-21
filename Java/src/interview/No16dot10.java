/*
 * Copyright (c) 7/20/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class No16dot10 {
    public int maxAliveYear(int[] birth, int[] death) {
        Arrays.sort(birth);
        Arrays.sort(death);
        int idx = 0;
        int max = 1;
        Map<Integer, Integer> mapper = new HashMap<>();
        mapper.put(birth[0], 1);
        for (int i = 1; i < birth.length; ++i) {
            int count = mapper.getOrDefault(birth[i - 1], 0) + 1;
            while (birth[i] > death[idx]) {
                --count;
                ++idx;
            }
            mapper.put(birth[i], count);
            max = Math.max(max, count);
        }
        for (int year : birth) if (mapper.get(year) == max) return year;
        return max;
    }

    public static void main(String[] args) {
    }
}
