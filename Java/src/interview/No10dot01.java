/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No10dot01 {
    public void merge(int[] A, int m, int[] B, int n) {
        int pA = m - 1, pB = n - 1;
        int idx = m + n - 1;

        while (pA >= 0 || pB >= 0) {
            if (pA < 0) A[idx--] = B[pB--];
            else if (pB < 0) A[idx--] = A[pA--];
            else if (A[pA] < B[pB]) A[idx--] = B[pB--];
            else A[idx--] = A[pA--];
        }
    }
}
