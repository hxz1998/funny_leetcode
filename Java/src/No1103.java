/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1103 {
    public int[] distributeCandies(int candies, int n) {
        int[] ans = new int[n];
        int idx = 0, count = 1;
        while (candies > 0) {
            if (candies >= count) ans[idx] += count;
            else ans[idx] += candies;
            candies -= count++;
            idx = (idx + 1) % n;
        }
        return ans;
    }

    public static void main(String[] args) {
        No1103 no1103 = new No1103();
        System.out.println(Arrays.toString(no1103.distributeCandies(10, 3)));
        System.out.println(Arrays.toString(no1103.distributeCandies(7, 4)));
    }
}
