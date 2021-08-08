/*
 * Copyright (c) 8/7/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No457 {
    public boolean circularArrayLoop(int[] nums) {
        for (int i = 0; i < nums.length; ++i) {
            if (check(nums, i)) return true;
        }
        return false;
    }

    private boolean check(int[] nums, int start) {
        int curr = start;
        int cnt = 1;
        int n = nums.length;
        boolean isNegative = nums[start] < 0;
        while (true) {
            if (cnt > n) return false;
            int next = ((curr + nums[curr]) % n + n) % n;
            if (isNegative && nums[next] > 0) return false;
            if (!isNegative && nums[next] < 0) return false;
            if (next == start) return cnt > 1;
            curr = next;
            cnt++;
        }
    }

    public static void main(String[] args) {
        int[] nums = {-2, -3, -9};
        No457 no457 = new No457();
        System.out.println(no457.circularArrayLoop(nums));
    }
}
