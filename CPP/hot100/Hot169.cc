/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};