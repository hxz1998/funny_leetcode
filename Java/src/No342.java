/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No342 {
    public boolean isPowerOfFour(int n) {
        for (int count = 0; count < 32; count += 2) {
            if ((1 << count) == n) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        No342 no342 = new No342();
        System.out.println(no342.isPowerOfFour(262144));
    }
}
