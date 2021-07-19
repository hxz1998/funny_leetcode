/*
 * Copyright (c) 7/19/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;

public class No16dot06 {
    public int smallestDifference(int[] a, int[] b) {
        Arrays.sort(a);
        Arrays.sort(b);
        int idxA = 0, idxB = 0;
        long min = Long.MAX_VALUE;
        while (idxA < a.length && idxB < b.length) {
            long diff = a[idxA] - b[idxB];
            min = Math.min(min, Math.abs(diff));
            if (a[idxA] < b[idxB]) ++idxA;
            else idxB++;
        }
        return (int) min;
    }

    public static void main(String[] args) {
        int[] a = {-2147483648, 1};
        int[] b = {2147483647, 0};
        No16dot06 no16dot06 = new No16dot06();
        System.out.println(no16dot06.smallestDifference(a, b));
    }
}
