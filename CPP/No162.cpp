/**
 * Created by Xiaozhong on 2020/8/16.
 * Copyright (c) 2020/8/16 Xiaozhong. All rights reserved.
 */
#include "vector"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        return search(nums, 0, nums.size() - 1);
    }

private:
    /*
     * 递归搜索结果：可以将整个序列看作是很多个小的递增或递减序列
     * 如果中间元素正好位于局部递减序列（nums[mid] > nums[mid + 1]）那么可以说明极大值位于左侧，此时调整右指针为 mid
     * 否则中间元素位于局部递增序列（nums[mid] < nums[mid + 1]）那么可以说明极大值位于右侧，此时调整左指针为 mid + 1
     */
    int search(vector<int> &nums, int left, int right) {
        if (left == right) return left;
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) return search(nums, left, mid);
        return search(nums, mid + 1, right);
    }
};