/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest233;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class No4 {
    public int countPairs(int[] nums, int low, int high) {
        int ans = 0;
        HashMap<Integer, Integer> mapper = new HashMap<>();
        for (int num : nums) mapper.put(num, mapper.getOrDefault(num, 0) + 1);
        Set<Map.Entry<Integer, Integer>> entrySet = mapper.entrySet();
        Iterator<Map.Entry<Integer, Integer>> iterator = entrySet.iterator();
        return ans;
    }

    public static void main(String[] args) {
        No4 no4 = new No4();
        System.out.println(no4.countPairs(new int[]{1, 4, 2, 7}, 2, 6));
    }
}
