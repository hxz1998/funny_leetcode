/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int p0 = 0, p1 = 0;
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (nums[idx] == 1) {
                swap(nums[idx], nums[p1]);
                p1++;
            } else if (nums[idx] == 0) {
                swap(nums[idx], nums[p0]);
                if (p0 < p1) swap(nums[p1], nums[p0]);
                p0++;
                p1++;
            }
        }
    }
};