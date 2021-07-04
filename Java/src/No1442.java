/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1442 {
    public int countTriplets(int[] arr) {
        int n = arr.length;
        int[] prev = new int[n];
        prev[0] = arr[0];
        for (int i = 1; i < n; ++i) prev[i] = prev[i - 1] ^ arr[i];
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int k = j; k < n; ++k) {
                    int left = prev[i] ^ prev[j] ^ arr[i];
                    int right = prev[j] ^ prev[k] ^ arr[j];
                    if (left == right) ans++;
                }
            }
        }
        return ans;
    }
}
