/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;

public class No436 {
    public int[] findRightInterval(int[][] intervals) {
        TreeMap<Integer, Integer> mapper = new TreeMap<>();
        int n = intervals.length;
        if (n <= 1) return new int[]{-1};
        for (int i = 0; i < n; ++i) mapper.put(intervals[i][0], i);
        int[][] arr = new int[mapper.size()][2];
        int idx = 0;
        for (Map.Entry<Integer, Integer> entry : mapper.entrySet()) {
            arr[idx][0] = entry.getKey();
            arr[idx++][1] = entry.getValue();
        }
        int[] ret = new int[n];
        for (int i = 0; i < n; ++i) {
//            ret[i] = binarySearch(arr, intervals[i][1]);
            Integer index = mapper.ceilingKey(intervals[i][1]);
            ret[i] = index == null ? -1 : mapper.get(index);
        }
        return ret;
    }

    // 大于 4 的第一个位置
    private int binarySearch(int[][] nums, int target) {
        int left = 0, right = nums.length - 1;
        if (nums[right][0] < target) return -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid][0] == target) return nums[mid][1];
            else if (nums[mid][0] < target) left = mid + 1;
            else right = mid;
        }
        return nums[left][1];
    }

    public static void main(String[] args) {
        int[][] intervals = {{3, 4}, {2, 3}, {1, 2}};
        No436 no436 = new No436();
        System.out.println(Arrays.toString(no436.findRightInterval(intervals)));
    }
}
