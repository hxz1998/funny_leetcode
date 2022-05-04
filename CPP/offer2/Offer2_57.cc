/**
 * Created by Xiaozhong on 2022/4/29.
 * Copyright (c) 2022/4/29 Xiaozhong. All rights reserved.
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
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        int n = static_cast<int>(nums.size());
        set<int> rec;
        for (int idx = 0; idx < n; ++idx) {
            auto iter = rec.lower_bound(max(nums[idx], INT32_MIN + t) - t);
            if (iter != rec.end() && *iter <= min(nums[idx], INT32_MAX - t) + t) return true;
            rec.insert(nums[idx]);
            if (idx >= k) rec.erase(nums[idx - k]);
        }
        return false;
    }
};