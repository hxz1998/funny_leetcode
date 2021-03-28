/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No16dot17 {
    static class Status {
        int lSum, rSum, mSum, iSum;

        public Status(int lSum, int rSum, int mSum, int iSum) {
            this.lSum = lSum; // 以 l 为左端点的最大子段和
            this.rSum = rSum; // 以 r 为右端点的最大子段和
            this.mSum = mSum; // [l, r] 内的最大子段和
            this.iSum = iSum; // [l, r] 的区间和
        }
    }

    public int maxSubArray(int[] nums) {
        return getInfo(nums, 0, nums.length - 1).mSum;
    }

    public Status getInfo(int[] a, int left, int right) {
        if (left == right) return new Status(a[left], a[left], a[left], a[left]);
        int m = (left + right) / 2;
        Status lSub = getInfo(a, left, m);
        Status rSub = getInfo(a, m + 1, right);
        return pushUp(lSub, rSub);
    }

    public Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = Math.max(l.lSum, l.iSum + r.lSum);
        int rSum = Math.max(r.rSum, r.iSum + l.rSum);
        int mSum = Math.max(l.rSum + r.lSum, Math.max(l.mSum, r.mSum));
        return new Status(lSum, rSum, mSum, iSum);
    }

    public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        No16dot17 no16dot17 = new No16dot17();
        System.out.println(no16dot17.maxSubArray(nums));
    }
}
