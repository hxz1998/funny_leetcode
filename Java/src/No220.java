/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.TreeSet;

public class No220 {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        int n = nums.length;
        // 有序集合，里面数据从小到大排序，但是只会让里面的数保持 k 个以内
        TreeSet<Long> set = new TreeSet<>();
        for (int i = 0; i < n; ++i) {
            // 找到大于 nums[i] - t 的最小的数，看看它是不是小于 nums[i] + t
            // 因为需要保证 nums[i] - t <= x <= nums[i] + t
            Long ceiling = set.ceiling((long) nums[i] - t);
            if (ceiling != null && ceiling <= (long) nums[i] + t) return true;
            // 没找到的话，就把当前数放到集合中，继续查找下一个
            set.add((long) nums[i]);
            // 保持容器内数据是 k 个及以内
            if (i >= k) set.remove((long) nums[i - k]);
        }
        return false;
    }

    public static void main(String[] args) {
        int[] nums = {1, 5, 9, 1, 5, 9};
        No220 no220 = new No220();
        System.out.println(no220.containsNearbyAlmostDuplicate(nums, 2, 3));
    }
}
