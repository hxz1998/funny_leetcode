/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No870 {
    public int[] advantageCount(int[] A, int[] B) {
        int size = A.length;
        Arrays.sort(A);
        int[][] pairs = new int[size][2];
        for (int i = 0; i < size; ++i) {
            pairs[i][0] = B[i];
            pairs[i][1] = i;
        }
        Arrays.sort(pairs, (a, b) -> a[0] - b[0]);
        int[] ret = new int[size];
        for (int i = 0, left = 0, right = size - 1; i < size; ++i) {
            if (A[i] <= pairs[left][0]) ret[pairs[right--][1]] = A[i];
            else ret[pairs[left++][1]] = A[i];
        }
        return ret;
    }

    public static void main(String[] args) {
        No870 no870 = new No870();
        int[] A = new int[]{2, 7, 11, 15};
        int[] B = new int[]{1, 10, 4, 11};
        System.out.println(Arrays.toString(no870.advantageCount(A, B)));
    }
}
