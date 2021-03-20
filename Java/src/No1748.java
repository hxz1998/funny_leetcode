/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.HashSet;

public class No1748 {
    public int sumOfUnique(int[] nums) {
        HashMap<Integer, Integer> mapper = new HashMap<>();
        int ans = 0; // 返回值
        for (int num : nums) {
            if (!mapper.containsKey(num)) {
                // 如果之前没出现过，那么就加上它
                ans += num;
                // 然后在哈希表中记录下来出现的次数
                mapper.put(num, 1);
            } else if (mapper.containsKey(num) && mapper.get(num) == 1) {
                // 如果出现过一次，就减去它，然后记录次数
                ans -= num;
                mapper.put(num, mapper.get(num) + 1);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 2};
        No1748 no1748 = new No1748();
        System.out.println(no1748.sumOfUnique(nums));
    }
}
