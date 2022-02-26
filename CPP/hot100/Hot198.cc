/**
 * Created by Xiaozhong on 2022/2/26.
 * Copyright (c) 2022/2/26 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        vector<int> dp(nums.size() + 1);
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (idx == 0) dp[idx + 1] = nums[idx];
            else dp[idx + 1] = max(dp[idx], dp[idx - 1] + nums[idx]);
        }
        return dp[nums.size()];
    }
};

