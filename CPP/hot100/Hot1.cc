/*
 * Created by Xiaozhong on 12/30/2021.
 * Copyright (c) 12/30/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mapper;
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (mapper.find(target - nums[idx]) != mapper.end()) return {idx, mapper[target - nums[idx]]};
            else mapper[nums[idx]] = idx;
        }
        return {};
    }
};