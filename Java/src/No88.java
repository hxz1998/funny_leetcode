/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No88 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // 首先创建辅助数组，把 nums1 中的数字拷贝下来到 aux 中
        int[] aux = new int[m];
        System.arraycopy(nums1, 0, aux, 0, m);
        // 然后和归并排序一样的思路，逐个放进来当前的最小值就好了
        // left 用来指向 aux 下标，right 用来指向 nums2 下标
        int left = 0, right = 0;
        for (int i = 0; i < m + n; ++i) {
            // left >= m 的时候，意味着 aux 里面的数已经转移完了，只需要把 nums2 中的数拷贝下来就好了
            if (left >= m) nums1[i] = nums2[right++];
            // 同样的，right >= n 的时候，意味着 nums2 中的数已经转移完了，只需要把 aux 中的数拷贝下来就好了
            else if (right >= n) nums1[i] = aux[left++];
            // 否则的话，就取两者的最小值就好了
            else if (aux[left] < nums2[right]) nums1[i] = aux[left++];
            else nums1[i] = nums2[right++];
        }
    }
}
