/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No932 {
    Map<Integer, int[]> mapper;

    public int[] beautifulArray(int N) {
        mapper = new HashMap<>();
        return recursion(N);
    }

    private int[] recursion(int n) {
        if (mapper.containsKey(n)) return mapper.get(n);
        int[] ans = new int[n];
        if (n == 1) ans[0] = 1;
        else {
            int idx = 0;
            for (int x : recursion((n + 1) / 2)) ans[idx++] = 2 * x - 1;
            for (int x : recursion(n / 2)) ans[idx++] = 2 * x;
        }
        mapper.put(n, ans);
        return ans;
    }
}
