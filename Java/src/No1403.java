/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No1403 {
    public List<Integer> minSubsequence(int[] nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        List<Integer> ret = new ArrayList<>();
        Arrays.sort(nums);
        int tmp = 0;
        for (int i = nums.length - 1; i >= 0; --i) {
            tmp += nums[i];
            ret.add(nums[i]);
            sum -= nums[i];
            if (tmp > sum) break;
        }
        return ret;
    }
}
