/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1337 {
    public int[] kWeakestRows(int[][] mat, int k) {
        int n = mat.length;
        // 存储每一行的战斗力和下标对应值，[战斗力，下标]
        int[][] strength = new int[n][2];
        for (int i = 0; i < n; ++i) {
            strength[i][0] = binarySearch(mat[i]);
            strength[i][1] = i;
        }
        // 然后根据战斗力升序排列，如果战斗力相同，就让下标升序排列
        Arrays.sort(strength, (o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o1[0] - o2[0]);
        // 找到前 k 个，进行处理
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) ans[i] = strength[i][1];
        return ans;
    }

    // 使用二分查找，找到最后一个 1 的位置 idx ，那么 idx - 0 就是当前行中 1 的个数
    private int binarySearch(int[] vector) {
        int left = 0, right = vector.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 如果 mid 指针指向的位置是 1 ，那么说明 mid 往左全部是 1，因此把left 指针往右移动一点
            if (vector[mid] == 1) left = mid + 1;
                // 否则的话，就把 right 指针往左移动
            else right = mid;
        }
        // 需要额外注意的是，如果当前行全部为 1， 因为 left 指针不会跑到数组外面，所以需要 + 1
        return vector[left] == 1 ? left + 1 : vector.length - left;
    }

    public static void main(String[] args) {
        int[][] matrix = {{1, 1, 0, 0, 0},
                {1, 1, 1, 1, 0},
                {1, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {1, 1, 1, 1, 1}};
        No1337 no1337 = new No1337();
        System.out.println(Arrays.toString(no1337.kWeakestRows(matrix, 3)));
    }
}
