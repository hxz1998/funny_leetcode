/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package offer;

import java.util.Arrays;

public class No51 {
    public int reversePairs(int[] nums) {
        int n = nums.length;
        int[] tmp = new int[n];
        return mergeSort(nums, tmp, 0, n - 1);
    }

    // 归并排序
    private int mergeSort(int[] nums, int[] tmp, int lo, int hi) {
        if (lo >= hi) return 0;
        // 找到归并排序的中间位置
        int mid = lo + (hi - lo) / 2;
        // 然后递归地去进行排序
        int invCount = mergeSort(nums, tmp, lo, mid) + mergeSort(nums, tmp, mid + 1, hi);
        // 把之前递归排序的结果进行归并
        int l = lo, r = mid + 1, pos = l;
        // 只要左指针没有碰到中间位置 mid，右指针没有触碰到最高位置 hi，就一直循环下去
        while (l <= mid && r <= hi) {
            if (nums[l] <= nums[r]) {
                tmp[pos++] = nums[l++];
                // 每次左指针右移的时候，就去累加右指针现在有的个数
                invCount += (r - (mid + 1));
            } else {
                // 对于右指针右移，直接复制下来就好了
                tmp[pos++] = nums[r++];
            }
        }
        // 对剩余的左边子数组进行拷贝，累加
        for (int k = l; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            invCount += (r - (mid + 1));
        }
        // 对右边的再进行这个过程
        for (int k = r; k <= hi; ++k) tmp[pos++] = nums[k];
        // 把临时数组中的内容拷贝回原来数组中
        for (int i = lo; i <= hi; ++i) nums[i] = tmp[i];
        return invCount;
    }

    public static void main(String[] args) {
        int[] nums = {7, 5, 6, 4};
        No51 no51 = new No51();
        System.out.println(no51.reversePairs(nums));
        nums = new int[]{233, 2000000001, 234, 2000000006, 235, 2000000003, 236, 2000000007, 237, 2000000002, 2000000005, 233, 233, 233, 233, 233, 2000000004};
        System.out.println(no51.reversePairs(nums));
    }
}
