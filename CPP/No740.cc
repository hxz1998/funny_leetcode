/**
 * Created by Xiaozhong on 2020/12/1.
 * Copyright (c) 2020/12/1 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums.back();
        int len = nums.size(), max_num = nums.front();
        for (int i = 0; i < len; ++i) {
            max_num = max(max_num, nums[i]);
        }
        // 构造新数组
        vector<int> count(max_num + 1);
        for (int item : nums) count[item]++;
        vector<int> dp(max_num + 1);
        dp[1] = count[1] * 1;
        dp[2] = max(dp[1], count[2] * 2);
        for (int i = 2; i <= max_num; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + i * count[i]);
        }
        return dp[max_num];
    }
};