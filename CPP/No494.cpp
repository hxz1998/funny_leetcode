/**
 * Created by Xiaozhong on 2020/10/2.
 * Copyright (c) 2020/10/2 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        // dp[i][j] 表示数组中的前 i 个元素，组成和为 j 的方案数
        // 对于第 i 个元素，可以使用 + 或 -
        vector<vector<int>> dp(nums.size(), vector<int>(2001, 0));
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int sum = -1000; sum <= 1000; ++sum) {
                if (dp[i - 1][sum + 1000] > 0) {
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        }
        return S > 1000 ? 0 : dp[nums.size() - 1][1000 + S];
    }
};
