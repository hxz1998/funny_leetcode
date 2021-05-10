/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Random;

public class No528 {
    static class Solution {
        int[] data;
        int[] prefix;
        int sum = 0;
        Random random = new Random();

        public Solution(int[] w) {
            data = w;
            int n = w.length;
            prefix = new int[n];
            prefix[0] = w[0];
            for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] + w[i];
            sum = prefix[n - 1];
        }

        public int pickIndex() {
            int target = random.nextInt(sum);
            int left = 0, right = prefix.length - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (prefix[mid] <= target) left = mid + 1;
                else right = mid;
            }
            return left;
        }
    }
}
