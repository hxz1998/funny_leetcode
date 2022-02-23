/**
 * Created by Xiaozhong on 2022/2/22.
 * Copyright (c) 2022/2/22 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[left] <= nums[mid]) {
                if (nums[mid] > target && nums[left] < target) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};