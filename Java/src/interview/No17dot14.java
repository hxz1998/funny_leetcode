/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;

public class No17dot14 {
    public int[] smallestK(int[] arr, int k) {
        if (k == 0 || arr.length == 0) return new int[0];
        return quickSort(arr, 0, arr.length - 1, k - 1);
    }

    private int[] quickSort(int[] arr, int lo, int hi, int k) {
        // 对数组进行划分操作，找到中间用来切分的位置
        int mid = partition(arr, lo, hi);
        // 解决左边的子问题，解决右边的子问题
        if (mid == k) return Arrays.copyOf(arr, mid + 1);
        return mid > k ? quickSort(arr, lo, mid - 1, k) : quickSort(arr, mid + 1, hi, k);
    }

    private int partition(int[] arr, int lo, int hi) {
        int left = lo, right = hi + 1;
        // 使用数组的第一个数进行左右排序
        int value = arr[lo];
        while (true) {
            // 左指针向右走，找到第一个大于 value 的位置并停下来
            while (arr[++left] <= value) if (left >= hi) break;
            // 右指针往左走，找到第一个小于 value 的元素并停下来
            while (arr[--right] >= value) if (right <= lo) break;
            // 如果左右指针都相遇了，那么就说明没有元素不符合要求了，直接跳出去就好了
            if (left >= right) break;
            // 交换左右指针指向的元素，确保左边的都小于 value， 右边的都大于 value
            exch(arr, left, right);
        }
        // 再把 value 放到合适的位置
        exch(arr, lo, right);
        // 并返回 value 放好之后的下标位置
        return right;
    }

    // 交换数组中的两个元素
    private void exch(int[] arr, int li, int ri) {
        int t = arr[li];
        arr[li] = arr[ri];
        arr[ri] = t;
    }

    public static void main(String[] args) {
        int[] arr = {3, 2, 1};
        No17dot14 no17dot14 = new No17dot14();
        System.out.println(Arrays.toString(no17dot14.smallestK(arr, 2)));
    }
}
