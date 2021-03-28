/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No17dot10 {
    public int majorityElement(int[] nums) {
        // prev 用来记录上一个有效的投票人，count用来记录他的有效投票数
        int prev = -1, count = 0;
        for (int i : nums) {
            // 如果 count == 0，说明之前的都抵消掉了，从新开始
            if (count == 0) {
                count++;
                prev = i;
            } else if (prev == i) {
                // 说明遇到了相同的投票，直接相加就好了
                count++;
            } else {
                // 说明遇到了不同的，那么就抵消掉一票
                --count;
            }
        }
        // 检查个数是不是真的超过了 1/2
        if (count > 0) {
            int n = 0;
            for (int i : nums) if (i == prev) n++;
            if (n > nums.length / 2) return prev;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] nums = {3, 2, 3};
        No17dot10 no17dot10 = new No17dot10();
        System.out.println(no17dot10.majorityElement(nums));
        nums = new int[]{1, 2, 5, 9, 5, 9, 5, 5, 5};
        System.out.println(no17dot10.majorityElement(nums));
        nums = new int[]{3, 2};
        System.out.println(no17dot10.majorityElement(nums));
        nums = new int[]{1, 2, 3};
        System.out.println(no17dot10.majorityElement(nums));
    }
}
