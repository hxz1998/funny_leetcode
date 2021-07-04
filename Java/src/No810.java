/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No810 {
    public boolean xorGame(int[] nums) {
        if (nums.length % 2 == 0) return true;
        int xor = 0;
        for (int num : nums) xor ^= num;
        return xor == 0;
    }
}
