/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class Sort {
    // 冒泡排序
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        // 每一次循环，都把最大的元素冒泡到对应的位置
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (less(arr, j + 1, j)) exch(arr, j, j + 1);
            }
        }
    }

    // 选择排序
    public static void selectionSort(int[] arr) {
        int n = arr.length;
        // 每一次循环，都会把剩余未排数组的最小值放到对应的位置上去
        for (int i = 0; i < n; ++i) {
            int min = i;
            for (int j = i + 1; j < n; ++j) {
                if (less(arr, j, min)) min = j;
            }
            exch(arr, min, i);
        }
    }

    // 插入排序
    public static void insertSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            for (int j = i; j > 0 && less(arr, j, j - 1); --j) {
                exch(arr, j, j - 1);
            }
        }
    }

    // 希尔排序
    public static void shellSort(int[] arr) {
        int n = arr.length;
        int h = 1;
        while (h < n / 3) h = 3 * h + 1;
        while (h >= 1) {
            for (int i = h; i < n; ++i) {
                for (int j = i; j >= h && less(arr, j, j - h); j -= h) exch(arr, j, j - h);
            }
            h /= 3;
        }
    }

    // 归并排序
    public static void mergeSort(int[] arr) {
        mergeSort(arr, 0, arr.length - 1, new int[arr.length]);
    }

    private static void mergeSort(int[] arr, int left, int right, int[] aux) {
        if (left >= right) return;
        // 找到切分中点位置
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, aux);             // 排序左边
        mergeSort(arr, mid + 1, right, aux);    // 排序右边
        merge(arr, left, mid, right, aux);          // 归并最后的结果
    }

    // 归并函数
    private static void merge(int[] arr, int left, int mid, int right, int[] aux) {
        for (int k = left; k <= right; ++k) aux[k] = arr[k];
        int i = left, j = mid + 1;
        for (int k = left; k <= right; ++k) {
            if (i > mid) arr[k] = aux[j++];         // 如果左半部分已经放完了，那么就只放右边的
            else if (j > right) arr[k] = aux[i++];  // 同样的，如果右半部分已经都放进去了，就只放左边的
            else if (less(aux, i, j)) arr[k] = aux[i++];    // 否则的话，捡着小的放
            else arr[k] = aux[j++];
        }
    }

    // 快速排序
    public static void quickSort(int[] arr) {
        quickSort(arr, 0, arr.length - 1);
    }

    private static void quickSort(int[] arr, int left, int right) {
        if (left > right) return;
        int mid = partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }

    private static int partition(int[] arr, int left, int right) {
        int val = arr[left];
        int lo = left, hi = right + 1;
        while (true) {
            while (arr[++lo] <= val) if (lo >= right) break;
            while (arr[--hi] >= val) if (hi <= left) break;
            if (lo >= hi) break;
            exch(arr, lo, hi);
        }
        exch(arr, left, hi);
        return hi;
    }

    // 堆排序
    public static void heapSort(int[] arr) {
        int n = arr.length;
        int[] heap = new int[n + 1];
        int idx = 0;
        for (int num : arr) {
            heap[++idx] = num;
            swim(heap, idx);
        }
        for (int i = 0; i < n; ++i) arr[i] = deleteMin(heap, idx--);
    }

    // 删除堆中的最小元素，并重新调整堆
    private static int deleteMin(int[] arr, int idx) {
        int ret = arr[1];
        exch(arr, 1, idx--);
        arr[idx + 1] = 0;
        sink(arr, 1, idx);
        return ret;
    }

    // 堆的下沉操作
    private static void sink(int[] arr, int k, int idx) {
        while (2 * k <= idx) {
            int j = 2 * k;
            if (j < idx && less(arr, j + 1, j)) ++j;
            if (!less(arr, j, k)) break;
            exch(arr, j, k);
            k = j;
        }
    }

    // 堆的上浮操作
    private static void swim(int[] arr, int idx) {
        while (idx > 1 && less(arr, idx, idx / 2)) {
            exch(arr, idx, idx / 2);
            idx /= 2;
        }
    }

    private static boolean less(int[] arr, int i, int j) {
        return arr[i] < arr[j];
    }

    private static void exch(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 2, 8, 7, 6, 6, 9, 2};
//        Sort.quickSort(arr);
//        Sort.selectionSort(arr);
//        Sort.bubbleSort(arr);
//        Sort.shellSort(arr);
//        Sort.heapSort(arr);
        Sort.mergeSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
