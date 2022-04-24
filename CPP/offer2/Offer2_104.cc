/**
 * Created by Xiaozhong on 2022/4/15.
 * Copyright (c) 2022/4/15 Xiaozhong. All rights reserved.
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
    int combinationSum4(vector<int> &nums, int target) {
        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;
        unordered_set<int> visited(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        for (int num = 1; num <= target; ++num) {
            for (int other: nums) {
                if (other > num) break;
                dp[num] += dp[num - other];
            }
        }
        return dp[target];
    }
};