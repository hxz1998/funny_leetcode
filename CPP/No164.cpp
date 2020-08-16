/**
 * Created by Xiaozhong on 2020/8/16.
 * Copyright (c) 2020/8/16 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) return 0;  // 题目特殊情况
        sort(nums.begin(), nums.end()); // 先排序
        int max_gap = 0;                // 用来记录最大间隔
        for (int i = 0; i < nums.size() - 1; i++) max_gap = max(max_gap, nums[i + 1] - nums[i]);    // 更新最大间隔
        return max_gap;
    }
};