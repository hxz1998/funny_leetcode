/**
 * Created by Xiaozhong on 2021/2/10.
 * Copyright (c) 2021/2/10 Xiaozhong. All rights reserved.
 */

public class No1658 {
    public int minOperations(int[] nums, int x) {
        // 记录序列总和是多少
        int sum = 0;
        for (int num : nums) sum += num;
        // target 是目标窗口结果，buffer 是当前窗口之和
        int target = sum - x, buffer = 0;
        // 如果发现窗口内数据已经小于0，那么就直接返回-1，因为所有数据都是大于0的，不可能和小于0
        if (target < 0) return -1;
        // left和right分别是窗口的左右边界，width是用来记录窗口宽度的
        int left = 0, right = 0, width = Integer.MIN_VALUE;
        // 只要左边界没有触碰到数组长度，那么就一直进行下去，每次右移一次左边界
        while (left < nums.length) {
            // 如果窗口里面的和小于目标窗口数据，就右移右边界进行扩张
            while (buffer < target && right < nums.length) buffer += nums[right++];
            // 如果扩张发现已经满足了要求，就记录下来当前的结果
            if (buffer == target) width = Math.max(width, right - left);
            // 对左边界进行右移，检查下一个窗口
            buffer -= nums[left++];
        }
        return width == Integer.MIN_VALUE ? -1 : nums.length - width;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1, 1, 4, 2, 3};
        System.out.println(new No1658().minOperations(nums, 5));
        nums = new int[]{3, 2, 20, 1, 1, 3};
        System.out.println(new No1658().minOperations(nums, 10));
    }
}
