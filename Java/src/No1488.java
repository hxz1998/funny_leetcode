/*
 * Copyright (c) 8/4/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No1488 {
    public int[] avoidFlood(int[] rains) {
        TreeSet<Integer> sunshine = new TreeSet<>();
        Map<Integer, Integer> rainyDay = new HashMap<>();
        int n = rains.length;
        int[] ans = new int[n];
        for (int day = 0; day < n; ++day) {
            int lake = rains[day];
            if (lake == 0) sunshine.add(day);
            else {
                if (rainyDay.containsKey(lake)) {
                    Integer before = sunshine.higher(rainyDay.get(lake));
                    if (before == null) return new int[]{};
                    ans[before] = lake;
                    sunshine.remove(before);
                    rainyDay.put(lake, day);
                } else {
                    rainyDay.put(lake, day);
                }
                ans[day] = -1;
            }
        }
        for (int idx = 0; idx < n; ++idx) if (ans[idx] == 0) ans[idx] = 1;
        return ans;
    }

    public static void main(String[] args) {
        No1488 no1488 = new No1488();
        int[] rains = {1, 0, 2, 0, 3, 0, 2, 0, 0, 0, 1, 2, 3};
        System.out.println(Arrays.toString(no1488.avoidFlood(rains)));
    }
}
