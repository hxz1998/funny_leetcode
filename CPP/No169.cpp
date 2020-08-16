/**
 * Created by Xiaozhong on 2020/8/16.
 * Copyright (c) 2020/8/16 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        // 因为出现的次数大于等于 n / 2 ，所以不管怎样都会在中间找到目标值
        return nums[nums.size() / 2];
    }
};