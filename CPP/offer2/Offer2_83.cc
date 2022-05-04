/**
 * Created by Xiaozhong on 2022/5/1.
 * Copyright (c) 2022/5/1 Xiaozhong. All rights reserved.
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
    void backtrack(const vector<int> &nums, vector<bool> &used,
                   vector<vector<int>> &ans, vector<int> &buffer) {
        if (buffer.size() == nums.size()) {
            ans.push_back(buffer);
            return;
        }
        for (int idx = 0; idx < static_cast<int>(nums.size()); ++idx) {
            if (!used[idx]) {
                used[idx] = true;
                buffer.push_back(nums[idx]);
                backtrack(nums, used, ans, buffer);
                buffer.pop_back();
                used[idx] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> buffer;
        vector<bool> used(nums.size());
        backtrack(nums, used, ans, buffer);
        return ans;
    }
};