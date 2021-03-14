/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest232;

import java.util.ArrayList;

public class No4 {
    static class Pair {
        int value, index;

        Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    public int maximumScore(int[] nums, int k) {
        int size = nums.length;
        int[] minArray = new int[size];
        int min = Integer.MAX_VALUE;
        for (int i = k; i < size; ++i) {
            if (nums[i] < min) min = nums[i];
            minArray[i] = min;
        }
        min = Integer.MAX_VALUE;
        for (int i = k - 1; i >= 0; --i) {
            if (nums[i] < min) min = nums[i];
            minArray[i] = min;
        }
        ArrayList<Pair> left = new ArrayList<>();
        left.add(new Pair(minArray[0], 0));
        for (int i = 1; i < k; ++i)
            if (left.get(left.size() - 1).value != minArray[i]) left.add(new Pair(minArray[i], i));

        ArrayList<Pair> right = new ArrayList<>();
        right.add(new Pair(nums[k], k));
        for (int i = k + 1; i < size; ++i)
            if (right.get(right.size() - 1).value != minArray[i]) right.add(new Pair(minArray[i], i));
            else right.get(right.size() - 1).index = i;
        int ans = 0;
        for (int i = 0; i < right.size(); ++i) {
            for (int j = left.size() - 1; j >= 0; --j) {
                int tmp = Math.min(left.get(j).value, right.get(i).value) * (right.get(i).index - left.get(j).index + 1);
                if (tmp >= ans) ans = tmp;
                else break;
            }
        }
        for (int i = 0; i < right.size(); ++i) {
            int tmp = Math.min(right.get(i).value, nums[k]) * (right.get(i).index - k + 1);
            ans = Math.max(ans, tmp);
        }
        for (int j = left.size() - 1; j >= 0; --j) {
            int tmp = Math.min(left.get(j).value, nums[k]) * (k - left.get(j).index + 1);
            ans = Math.max(ans, tmp);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1, 4, 3, 7, 4, 5};
        No4 no4 = new No4();
        nums = new int[]{5, 5, 4, 5, 4, 1, 1, 1};
        nums = new int[]{8182, 1273, 9847, 6230, 52, 1467, 6062, 726, 4852, 4507, 2460, 2041, 500, 1025, 5524};
        System.out.println(no4.maximumScore(nums, 8));
    }
}
