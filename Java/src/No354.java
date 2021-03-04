/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class No354 {
    public int maxEnvelopes(int[][] envelopes) {
        int size = envelopes.length;
        if (size == 0) return 0;
        Arrays.sort(envelopes, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] == o2[0] ? o2[1] - o1[1] : o1[0] - o2[0];
            }
        });

        List<Integer> ans = new ArrayList<>();
        ans.add(envelopes[0][1]);
        for (int i = 1; i < size; ++i) {
            int num = envelopes[i][1];
            if (num > ans.get(ans.size() - 1)) {
                ans.add(num);
            } else {
                int idx = binarySearch(ans, num);
                ans.set(idx, num);
            }
        }
        return ans.size();
    }

    private int binarySearch(List<Integer> list, int num) {
        int left = 0, right = list.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) < num) left = mid + 1;
            else right = mid;
        }
        return left;
    }
}
