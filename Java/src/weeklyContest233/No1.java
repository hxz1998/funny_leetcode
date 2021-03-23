/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest233;

public class No1 {
    public int maxAscendingSum(int[] nums) {
        int ans = nums[0], tmp = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            // 看看是否是递增的，如果递增，那么就直接加上该值
            if (nums[i] > nums[i - 1]) tmp += nums[i];
            else {
                // 如果当前元素小于前一个，那么就直接更新最大值
                ans = Math.max(tmp, ans);
                // 然后再记录下来当前值，从当前开始再检查
                tmp = nums[i];
            }
        }
        // 需要注意最后一个也要检查一下
        return Math.max(ans, tmp);
    }

    public static void main(String[] args) {
        int[] nums = {10, 20, 30, 5, 10, 50};
        No1 no1 = new No1();
        System.out.println(no1.maxAscendingSum(nums));
        nums = new int[]{12, 17, 15, 13, 10, 11, 12};
        System.out.println(no1.maxAscendingSum(nums));
        nums = new int[]{100};
        System.out.println(no1.maxAscendingSum(nums));
    }
}
