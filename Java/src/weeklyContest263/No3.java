/*
 * Copyright (c) 10/17/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest263;

public class No3 {
    private int ans = 0;

    public int countMaxOrSubsets(int[] nums) {
        int sum = 0;
        for (int num : nums) sum |= num;
        for (int i = 0; i < nums.length; ++i)
            dfs(nums, i, 0, sum);
        return ans;
    }

    // curr 表示当前已有的或值， idx 表示从哪里开始
    private void dfs(int[] nums, int idx, int curr, int target) {
        if (idx == nums.length) {
            if (curr == target) ans++;
            return;
        }
        dfs(nums, idx + 1, curr | nums[idx], target);
        dfs(nums, idx + 1, curr, target);
    }

    public static void main(String[] args) {
        int[] nums = {3, 1};
        No3 no3 = new No3();
        System.out.println(no3.countMaxOrSubsets(nums));
    }
}
