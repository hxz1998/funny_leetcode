/**
 * Created by Xiaozhong on 2021/1/28.
 * Copyright (c) 2021/1/28 Xiaozhong. All rights reserved.
 */

class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for (int i : nums) sum += i;
        int left_sum = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (sum - left_sum - nums[i] == left_sum) return i;
            left_sum += nums[i];
        }
        return -1;
    }
}

class Test {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 7, 3, 6, 5, 6};
        System.out.println(solution.pivotIndex(nums));
        nums = new int[]{-1, -1, -1, 0, 1, 1};
        System.out.println(solution.pivotIndex(nums));
    }
}
