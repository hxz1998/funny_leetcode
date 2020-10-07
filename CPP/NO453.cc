/**
 * Created by Xiaozhong on 2020/9/25.
 * Copyright (c) 2020/9/25 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            count += nums[i] - nums.front();
        }
        return count;
    }
};