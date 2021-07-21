/*
 * Copyright (c) 7/20/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.TreeSet;

public class No16dot11 {
    public int[] divingBoard(int shorter, int longer, int k) {
        if (k == 0) return new int[]{};
        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 0; i <= k; ++i) {
            set.add(shorter * i + longer * (k - i));
        }
        int[] ans = new int[set.size()];
        int idx = 0;
        for (int num : set) ans[idx++] = num;
        return ans;
    }
}
