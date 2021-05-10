/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashSet;
import java.util.Set;

public class No137 {
    public int singleNumber(int[] nums) {
        Set<Long> set = new HashSet<>();
        long sum = 0;
        for (long num : nums) {
            sum += num;
            set.add(num);
        }
        long sumSet = 0;
        for (long num : set) sumSet += num;
        return (int) ((3 * sumSet - sum) / 2);
    }

    public static void main(String[] args) {
        int[] nums = {43, 16, 45, 89, 45, -2147483648, 45, 2147483646, -2147483647, -2147483648, 43, 2147483647, -2147483646, -2147483648, 89, -2147483646, 89, -2147483646, -2147483647, 2147483646, -2147483647, 16, 16, 2147483646, 43};
        No137 no137 = new No137();
        System.out.println(no137.singleNumber(nums));
    }
}
