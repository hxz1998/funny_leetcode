/*
 * Copyright (c) 7/12/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest249;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.logging.Handler;

public class No3 {
    private static final int MOD = 1_000_000_007;

    public int colorTheGrid(int m, int n) {
        Map<Integer, List<Integer>> valid = new HashMap<>();
        int maskEnd = (int) Math.pow(3, m);
        for (int mask = 0; mask < maskEnd; ++mask) {
            List<Integer> color = new ArrayList<>();
            int mm = mask;
            for (int i = 0; i < m; ++i) {
                color.add(mm % 3);
                mm /= 3;
            }
            boolean check = true;
            for (int i = 0; i < m - 1; ++i) {
                if (color.get(i).equals(color.get(i + 1))) {
                    check = false;
                    break;
                }
            }
            if (check) valid.put(mask, color);
        }
        Map<Integer, List<Integer>> adjacent = new HashMap<>();
        for (Map.Entry<Integer, List<Integer>> entry1 : valid.entrySet()) {
            for (Map.Entry<Integer, List<Integer>> entry2 : valid.entrySet()) {
                boolean check = true;
                for (int i = 0; i < m; ++i) {
                    if (entry1.getValue().equals(entry2.getValue())) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    List<Integer> list = adjacent.getOrDefault(entry1.getKey(), new ArrayList<>());
                    list.add(entry2.getKey());
                    adjacent.put(entry1.getKey(), list);
                }
            }
        }
        int[] f = new int[maskEnd];
        for (Map.Entry<Integer, List<Integer>> entry : valid.entrySet()) {
            f[entry.getKey()] = 1;
        }
        for (int i = 1; i < n; ++i) {
            int[] g = new int[maskEnd];
            for (Map.Entry<Integer, List<Integer>> entry : valid.entrySet()) {
                for (int mask : adjacent.get(entry.getKey())) {
                    g[entry.getKey()] += f[mask];
                    if (g[entry.getKey()] >= MOD) g[entry.getKey()] -= MOD;
                }
            }
            System.arraycopy(g, 0, f, 0, g.length);
        }
        int ans = 0;
        for (int num : f) {
            ans += num;
            if (ans >= MOD) ans -= MOD;
        }
        return ans;
    }

    public static void main(String[] args) {
        No3 no3 = new No3();
        System.out.println(no3.colorTheGrid(5, 5));
    }
}
