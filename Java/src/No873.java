/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashSet;
import java.util.Set;

public class No873 {
    public int lenLongestFibSubseq(int[] arr) {
        int size = arr.length;
        Set<Integer> set = new HashSet<>();
        for (int x : arr) set.add(x);

        int ans = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                int x = arr[j], y = arr[i] + arr[j];
                int length = 2;
                while (set.contains(y)) {
                    int tmp = y;
                    y += x;
                    x = tmp;
                    ans = Math.max(ans, ++length);
                }
            }
        }
        return ans >= 3 ? ans : 0;
    }
}
