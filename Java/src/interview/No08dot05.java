/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No08dot05 {
    public int multiply(int A, int B) {
        return helper(Math.min(A, B), Math.max(A, B));
    }

    private int helper(int smaller, int bigger) {
        if (smaller == 0) return 0;
        else if (smaller == 1) return bigger;

        int s = smaller >> 1;
        int side1 = helper(s, bigger);
        int side2 = side1;
        if (smaller % 2 == 1) side2 = helper(smaller - s, bigger);
        return side1 + side2;
    }

}
