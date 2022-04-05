/**
 * Created by Xiaozhong on 2022/4/3.
 * Copyright (c) 2022/4/3 Xiaozhong. All rights reserved.
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
    void backtrack(const vector<int> &nums, vector<vector<int>> &ans, vector<int> &buffer, vector<bool> &used) {
        if (buffer.size() == nums.size()) {
            ans.push_back(buffer);
            return;
        }
        int n = static_cast<int>(nums.size());
        for (int idx = 0; idx < n; ++idx) {
            if (used[idx] || (idx > 0 && used[idx - 1] && nums[idx] == nums[idx - 1])) continue;
            buffer.push_back(nums[idx]);
            used[idx] = true;
            backtrack(nums, ans, buffer, used);
            buffer.pop_back();
            used[idx] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        vector<bool> used(n, false);
        vector<int> buffer;
        vector<vector<int>> ans;
        for (int idx = 0; idx < n; ++idx) {
            used = vector<bool>(n, false);
            buffer = vector<int>();
            used[idx] = true;
            buffer.push_back(nums[idx]);
            backtrack(nums, ans, buffer, used);
        }
        return ans;
    }
};