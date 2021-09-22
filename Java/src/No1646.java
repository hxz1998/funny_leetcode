/*
 * Copyright (c) 8/23/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1646 {
    public int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int[] nums = new int[n + 1];
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0) nums[i] = nums[i / 2];
            else nums[i] = nums[i / 2] + nums[i / 2 + 1];
        }
        return Arrays.stream(nums).max().getAsInt();
    }

    public static void main(String[] args) {
        No1646 no1646 = new No1646();
        System.out.println(no1646.getMaximumGenerated(7));
        System.out.println(no1646.getMaximumGenerated(3));
        System.out.println(no1646.getMaximumGenerated(15));
    }
}
