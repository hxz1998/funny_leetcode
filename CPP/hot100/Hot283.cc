/*
 * Created by Xiaozhong on 3/1/2022.
 * Copyright (c) 3/1/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        size_t n = nums.size();
        size_t zero = 0, notZero = 0;
        while (true) {
            while (zero < n && nums[zero] != 0) zero++;
            while (notZero < n && nums[notZero] == 0) notZero++;
            if (zero == n) return;
            swap(nums[zero], nums[notZero]);
        }
    }
};