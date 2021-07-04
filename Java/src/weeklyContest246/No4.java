/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest246;

import java.util.Arrays;

public class No4 {
    public int[] minDifference(int[] nums, int[][] queries) {
        int[] ans = new int[queries.length];
        if (Arrays.stream(nums).max() == Arrays.stream(nums).min()) {
            Arrays.fill(ans, -1);
            return ans;
        }
        int n = nums.length;
        int[] aux = new int[n];
        aux[0] = Integer.MAX_VALUE;
        for (int i = 1; i < n; ++i) aux[i] = nums[i] - nums[i - 1] == 0 ? Integer.MAX_VALUE : nums[i] - nums[i - 1];
        for (int idx = 0; idx < queries.length; ++idx) {
            int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
            for (int i = queries[idx][0]; i <= queries[idx][1]; ++i) {
                min = Math.min(min, nums[i]);
                max = Math.max(max, nums[i]);
            }
            if (min == max) ans[idx] = -1;
            else if (queries[idx][1] - queries[idx][0] == 1) ans[idx] = nums[queries[idx][1]] - nums[queries[idx][0]];
            else ans[idx] = helper(aux, queries[idx][0], queries[idx][1]);
        }
        return ans;
    }

    private int helper(int[] aux, int left, int right) {
        int ret = Integer.MAX_VALUE - 1000;
        int sum = ret;
        int min = Integer.MAX_VALUE;
        for (int i = left; i <= right; ++i) {
            if (aux[i] == Integer.MAX_VALUE || (aux[i] + sum > sum && sum != 0)) sum = 0;
            else {
                sum += aux[i];
                ret = Math.min(ret, Math.abs(sum));
            }
            min = Math.min(min, Math.abs(aux[i]));
        }
        return Math.min(ret, min);
    }

    private int maxSubSum(int[] arr) {
        int max = 0, sum = 0;
        for (int i = 0; i < arr.length; ++i) {
            sum += arr[i];
            if (sum > max) max = sum;
            else if (sum < 0) sum = 0;
        }
        return max;
    }

    private int minSubSum(int[] arr) {
        for (int i = 0; i < arr.length; ++i) arr[i] = arr[i] * -1;
        return (-1) * maxSubSum(arr);
    }

    public static void main(String[] args) {
        int[] nums = {4, 5, 2, 2, 7, 10};
        No4 no4 = new No4();
        int[][] queries = {{0, 2}, {0, 5}, {3, 5}};
        System.out.println(Arrays.toString(no4.minDifference(nums, queries)));
        int[] arr = {Integer.MAX_VALUE, 1, -3, Integer.MAX_VALUE, 5, 3};
        System.out.println(no4.minSubSum(arr));
    }
}
