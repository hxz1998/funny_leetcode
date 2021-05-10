/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1482 {
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        if (m * k > n) return -1;
        int left = 1, right = Arrays.stream(bloomDay).max().getAsInt();
        while (left < right) {
            int mid = (left + right) >> 1;
            int count = 0, bunchCount = 0;
            for (int day : bloomDay) {
                if (day <= mid) count++;
                else count = 0;
                if (count >= k) {
                    bunchCount++;
                    count = 0;
                }
            }
            if (bunchCount >= m) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    public static void main(String[] args) {
        No1482 no1482 = new No1482();
        int[] bloomDay = {7, 7, 7, 7, 12, 7, 7};
        System.out.println(no1482.minDays(bloomDay, 2, 3));
    }
}
