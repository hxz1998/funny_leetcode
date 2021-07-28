/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class No1713 {
    public int minOperations(int[] target, int[] arr) {
        int n = target.length;
        Map<Integer, Integer> mapper = new HashMap<>();
        for (int idx = 0; idx < n; ++idx) mapper.put(target[idx], idx);
        List<Integer> list = new ArrayList<>();
        for (int val : arr) {
            if (mapper.containsKey(val)) {
                int idx = mapper.get(val);
                int it = binarySearch(list, idx);
                if (it == list.size()) {
                    list.add(idx);
                } else {
                    list.set(it, idx);
                }
            }
        }
        return n - list.size();
    }

    private int binarySearch(List<Integer> list, int target) {
        int size = list.size();
        if (size == 0 || list.get(size - 1) < target) return size;
        int left = 0, right = size - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) < target) left = left + 1;
            else right = mid;
        }
        return left;
    }
}
