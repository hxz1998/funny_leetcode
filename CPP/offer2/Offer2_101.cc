/**
 * Created by Xiaozhong on 2022/3/17.
 * Copyright (c) 2022/3/17 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        if (nums[n - 1] > target) return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
        // dp[i][j] 就是 前 i 个元素，能不能构成 j
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (!dp[i][j] && j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }
};