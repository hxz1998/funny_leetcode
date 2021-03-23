/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No191 {
    public int hammingWeight(int n) {
        int ans = 0, index = 0;
        while (index <= 31) {
            if ((n & (1 << index++)) != 0) ++ans;
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(new No191().hammingWeight(11));
    }
}
