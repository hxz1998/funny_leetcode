/*
 * Created by Xiaozhong on 11/30/2021.
 * Copyright (c) 11/30/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        if (nums.empty()) return -1;
        for (int idx = 0; idx < nums.size(); ++idx) {
            while (nums[idx] != idx) {
                if (nums[idx] == nums[nums[idx]]) return nums[idx];
                swap(nums, idx, nums[idx]);
            }
        }
        return -1;
    }

private:
    void swap(vector<int> &nums, const int left, const int right) {
        int t = nums[left];
        nums[left] = nums[right];
        nums[right] = t;
    }
};

