/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No645 {
    public int[] findErrorNums(int[] nums) {
        Arrays.sort(nums);
        int sum = nums[0];
        int[] ret = new int[2];
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == nums[i - 1]) ret[0] = nums[i];
            sum += nums[i];
        }
        ret[1] = ret[0] - (sum - (1 + nums.length) * nums.length / 2);
        return ret;
    }

    public static void main(String[] args) {
        No645 no645 = new No645();
        int[] nums = {3, 2, 3, 4, 6, 5};
        System.out.println(Arrays.toString(no645.findErrorNums(nums)));
    }
}
