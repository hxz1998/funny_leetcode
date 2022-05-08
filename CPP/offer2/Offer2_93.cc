/**
 * Created by Xiaozhong on 2022/5/5.
 * Copyright (c) 2022/5/5 Xiaozhong. All rights reserved.
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
    int lenLongestFibSubseq(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        unordered_map<int, int> mapper;
        for (int idx = 0; idx < n; ++idx) mapper[nums[idx]] = idx;
        vector<vector<int>> dp(n, vector<int>(n));
        int ans = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = (mapper.find(nums[i] - nums[j]) != mapper.end()) ? mapper[nums[i] - nums[j]] : -1;
                dp[i][j] = k >= 0 && k < j ? dp[j][k] + 1 : 2;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};