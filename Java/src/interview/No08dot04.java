/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.List;

public class No08dot04 {
    public List<List<Integer>> subsets(int[] nums) {
        return subSets(nums, 0);
    }

    private List<List<Integer>> subSets(int[] nums, int idx) {
        List<List<Integer>> allSubs;
        if (idx == nums.length) {
            allSubs = new ArrayList<>();
            allSubs.add(new ArrayList<>());
        } else {
            allSubs = subSets(nums, idx + 1);
            int value = nums[idx];
            List<List<Integer>> more = new ArrayList<>();
            for (List<Integer> item : allSubs) {
                ArrayList<Integer> newSub = new ArrayList<>(item);
                newSub.add(value);
                more.add(newSub);
            }
            allSubs.addAll(more);
        }
        return allSubs;
    }
}
