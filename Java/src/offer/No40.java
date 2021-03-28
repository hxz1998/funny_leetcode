/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package offer;

import java.util.Arrays;

public class No40 {
    public int[] getLeastNumbers(int[] arr, int k) {
        quickSort(arr, 0, arr.length - 1);
        // 拷贝出来一个长度为 k ，从 0 开始计数的数组
        return Arrays.copyOf(arr, k);
    }

    // 快速排序
    private void quickSort(int[] arr, int lo, int hi) {
        if (hi <= lo) return;
        // 找到在哪里切分好了
        int mid = partition(arr, lo, hi);
        // 分治，分别对两个子数组进行切分排序
        quickSort(arr, lo, mid - 1);
        quickSort(arr, mid + 1, hi);
    }

    // 用来找切分点的函数
    private int partition(int[] arr, int lo, int hi) {
        // lo 位置实际上是切分点元素的值，right 之所以要从 hi + 1 开始是为了下面的循环方便。
        int left = lo, right = hi + 1;
        int value = arr[lo];
        while (true) {
            // 左指针不停的向右移动，找到第一个 小于 value 的元素然后停下来，准备交换。
            while (arr[++left] < value) if (left >= hi) break;
            // 右指针不断向左移动，找到第一个 大于 value 的元素然后停下来，准备和左指针交换。
            while (arr[--right] > value) if (right <= lo) break;
            // 如果左右指针相遇了，那么就跳出来循环，不再继续了
            if (left >= right) break;
            // 然后把左右指针指向的元素交换
            exch(arr, left, right);
        }
        // 把排头元素放到已经分好的位置
        exch(arr, lo, right);
        return right;
    }

    private void exch(int[] arr, int lhs, int rhs) {
        int t = arr[lhs];
        arr[lhs] = arr[rhs];
        arr[rhs] = t;
    }

    public static void main(String[] args) {
        int[] arr = {4, 5, 1, 6, 2, 7, 3, 8};
        No40 no40 = new No40();
        System.out.println(Arrays.toString(no40.getLeastNumbers(arr, 4)));
    }
}
