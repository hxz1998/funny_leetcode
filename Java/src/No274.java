/*
 * Copyright (c) 7/11/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No274 {
    public int hIndex(int[] citations) {
        int n = citations.length;
        Integer[] nums = new Integer[n];
        for (int i = 0; i < n; ++i) nums[i] = citations[i];
        Arrays.sort(nums, (o1, o2) -> o2 - o1);
        for (int i = 0; i < n; ++i) {
            if (nums[i] < i + 1) return i;
        }
        return n;
    }

    public static void main(String[] args) {
        int[] citations = {1, 3, 1};
        No274 no274 = new No274();
        System.out.println(no274.hIndex(citations));
    }
}
