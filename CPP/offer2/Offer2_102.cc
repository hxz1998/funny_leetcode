/**
 * Created by Xiaozhong on 2022/5/4.
 * Copyright (c) 2022/5/4 Xiaozhong. All rights reserved.
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
    void backtrack(const vector<int> &nums, int index, int buffer, int &ans, const int target) {
        if (index == nums.size()) {
            if (buffer == target) ans++;
            return;
        }
        backtrack(nums, index + 1, buffer + nums[index], ans, target);
        backtrack(nums, index + 1, buffer - nums[index], ans, target);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int ans = 0;
        backtrack(nums, 0, 0, ans, target);
        return ans;
    }
};