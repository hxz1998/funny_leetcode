/**
 * Created by Xiaozhong on 2022/4/5.
 * Copyright (c) 2022/4/5 Xiaozhong. All rights reserved.
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
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        if (n == 1) return nums[0];
        else if (n == 0) return 0;
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};