/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No10dot03 {
    public int search(int[] arr, int target) {
        return binarySearch(arr, 0, arr.length - 1, target);
    }

    private int binarySearch(int[] arr, int left, int right, int target) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            // 找到了相同的, 那么开始尝试寻找最小的下标
            // 如果 0 位置处等于 target, 那么直接返回 0
            if (arr[0] == target) return 0;
            int t = mid;
            // 否则的话, 就向左尝试寻找更小的
            while (t > 0 && arr[t - 1] == target) t--;
            return t;
        }
        if (right <= left) return -1;

        if (arr[left] < arr[mid]) {
            // 左边整体有序情况
            // 目标值可能位于左半边
            if (arr[mid] > target && target >= arr[left]) return binarySearch(arr, left, mid - 1, target);
            // 目标值可能位于右半边
            else return binarySearch(arr, mid + 1, right, target);
        } else if (arr[left] > arr[mid]) {
            // 右边整体有序
            // 目标值可能位于右半边
            if (arr[mid] < target && arr[right] >= target) return binarySearch(arr, mid + 1, right, target);
            // 目标值可能位于左半边
            else return binarySearch(arr, left, mid - 1, target);
        } else if (arr[left] == arr[mid]) {
            // 左半边数都是一样的
            if (arr[mid] == arr[right]) {
                // 两边数一样, 那么就在两边分别查找一次
                int res = binarySearch(arr, left, mid - 1, target);
                if (res == -1) return binarySearch(arr, mid + 1, right, target);
                return res;
            } else {
                // 否则的话, 就只在右边找一次, 因为左半边数都是一样的!
                return binarySearch(arr, mid + 1, right, target);
            }
        }
        return -1;
    }


    public static void main(String[] args) {
        No10dot03 no10dot03 = new No10dot03();
        int[] arr = {1, 1, 1, 1, 1, 2, 1, 1, 1};
        System.out.println(no10dot03.search(arr, 2));
        arr = new int[]{5, 5, 5, 1, 2, 3, 4, 5};
        System.out.println(no10dot03.search(arr, 5));
        arr = new int[]{21, 21, -21, -20, -17, -8, -6, -2, -2, -1, 0, 2, 3, 4, 4, 6, 11, 13, 14, 16, 17, 18, 20};
        System.out.println(no10dot03.search(arr, 4));
    }
}
