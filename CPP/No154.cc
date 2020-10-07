/**
 * Created by Xiaozhong on 2020/8/15.
 * Copyright (c) 2020/8/15 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;    // 除掉重复元素，而且不会丢失最小值（因为left没动）
            }
        }
        return nums[left];  // 因为数组是升序，所以直接取到左边最小值就可以了
    }
};