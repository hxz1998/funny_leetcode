/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1004 {
    public int longestOnes(int[] A, int K) {
        int size = A.length;
        // left 和 right 分别表示窗口的两个指针，rightSum 表示从0到right的和，leftSum同理
        int left = 0, right = 0, leftSum = 0, rightSum = 0, ans = Integer.MIN_VALUE;
        for (; right < size; ++right) {
            // rightSum += 1 - A[right] 省去了将原来数组中的 1 变成 0， 0 反过来变成 1 的操作
            rightSum += 1 - A[right];
            while (rightSum - leftSum > K) {
                leftSum += 1 - A[left];
                left++;
            }
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] A = new int[]{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
        No1004 no1004 = new No1004();
        System.out.println(no1004.longestOnes(A, 2));
    }
}
