/*
 * Copyright (c) 8/13/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1304 {
    public int[] sumZero(int n) {
        int[] ans = new int[n];
        if (n % 2 == 0) {
            for (int i = 1; i < n; i += 2) {
                ans[i - 1] = i;
                ans[i] = -1;
            }
        } else {
            ans[0] = 0;
            for (int i = 1; i < n - 1; i += 2) {
                ans[i] = -i;
                ans[i + 1] = i;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        No1304 no1304 = new No1304();
        System.out.println(Arrays.toString(no1304.sumZero(5)));
    }
}
