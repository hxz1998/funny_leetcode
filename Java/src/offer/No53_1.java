/*
 * Copyright (c) 7/16/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package offer;

public class No53_1 {
    public int search(int[] nums, int target) {
        if (nums.length == 0) return 0;
        // 找到左边界
        int left = binarySearch(nums, target, true);
        // 找到右边界
        int right = binarySearch(nums, target, false);
        // 首先排除没找到（最左边的数都比target大）的情况
        if (left < 0 || right < 0) return 0;
        // 然后检查最左边的数虽然比 target 小，最右边的数虽然比 target 大，但是最终没找到的情况
        else if (left == right) return nums[left] == target ? 1 : 0;
        // 最后就是一般情况了
        else return right - left + 1;
    }

    private int binarySearch(int[] nums, int target, boolean lower) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 如果是找左边界，那么直接让 right 定位到 mid，就跟一般的二分查找一样思路
            if (lower && nums[mid] >= target) right = mid;
            // 如果是找右边界，那么需要让 right 等于 mid 的前一个位置 mid - 1
            else if (!lower && nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        // 最后根据查找结果进行返回
        return nums[left] == target ? left : left - 1;
    }

    public static void main(String[] args) {
        No53_1 no53_1 = new No53_1();
        int[] nums = {5, 7, 7, 8, 8, 10};
        System.out.println(no53_1.search(nums, 8));
        System.out.println(no53_1.search(nums, 6));
        nums = new int[]{1};
        System.out.println(no53_1.search(nums, 0));
    }
}
