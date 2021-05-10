/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Comparator;

public class No179 {
    public String largestNumber(int[] nums) {
        int n = nums.length;

        Integer[] numbers = new Integer[n];
        for (int idx = 0; idx < n; ++idx) numbers[idx] = nums[idx];

        Arrays.sort(numbers, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return (o2.toString() + o1.toString()).compareTo(o1.toString() + o2.toString());
            }
        });

        StringBuilder builder = new StringBuilder();
        for (Integer integer : numbers) builder.append(integer.toString());
        return builder.toString();
    }
}
