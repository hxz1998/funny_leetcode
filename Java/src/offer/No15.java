/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package offer;

public class No15 {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = n < 0 ? 1 : 0;
        while (n != 0) {
            ans += (n & 1);
            n >>>= 1;
        }
        return ans;
    }

    public static void main(String[] args) {
        No15 no15 = new No15();
        System.out.println(no15.hammingWeight(-15));
    }
}
