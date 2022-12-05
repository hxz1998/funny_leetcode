/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Comparator;

public class No870 {
    // public int[] advantageCount(int[] A, int[] B) {
    //     int size = A.length;
    //     Arrays.sort(A);
    //     int[][] pairs = new int[size][2];
    //     for (int i = 0; i < size; ++i) {
    //         pairs[i][0] = B[i];
    //         pairs[i][1] = i;
    //     }
    //     Arrays.sort(pairs, (a, b) -> a[0] - b[0]);
    //     int[] ret = new int[size];
    //     for (int i = 0, left = 0, right = size - 1; i < size; ++i) {
    //         if (A[i] <= pairs[left][0]) ret[pairs[right--][1]] = A[i];
    //         else ret[pairs[left++][1]] = A[i];
    //     }
    //     return ret;
    // }

    public int[] advantageCount(int[] nums1, int[] nums2) {
        int n = nums1.length;
        Arrays.sort(nums1);
        int[][] pairs = new int[n][2];
        for (int i = 0; i < n; ++i) {
            pairs[i][0] = nums2[i];
            pairs[i][1] = i;
        }
        /*
         * 田忌赛马思路
         *
         * n1 从小到大排好序
         * n2 也从小到大排好序，但是记录自己原来的位置
         * 然后开始便利 n1[i]，并且填充返回值数组
         * 当 n1 当前位置 i 的数小于 n2 排序后当前位置最小值，则说明 n1 这个位置的值没有用了，直接放到最后面
         * 否则的话，找到当前位置
         */
        int[] ret = new int[n];
        Arrays.sort(pairs, Comparator.comparingInt(o -> o[0]));
        for (int i = 0, l = 0, r = n - 1; i < n; i++) {
            if (nums1[i] <= pairs[i][0]) ret[pairs[r--][1]] = nums1[i];
            else ret[pairs[l++][1]] = nums1[i];
        }
        return ret;
    }


    public static void main(String[] args) {
        No870 no870 = new No870();
        int[] A = new int[]{2, 7, 11, 15};
        int[] B = new int[]{1, 10, 4, 11};
        System.out.println(Arrays.toString(no870.advantageCount(A, B)));
    }
}
