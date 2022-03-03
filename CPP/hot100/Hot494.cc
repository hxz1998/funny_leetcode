/*
 * Created by Xiaozhong on 3/3/2022.
 * Copyright (c) 3/3/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
private:
    int ans = 0;

    void helper(const vector<int> &nums, int target, int start, int curr) {
        if (start == nums.size()) {
            if (curr == target) ans++;
            return;
        }
        helper(nums, target, start + 1, curr + nums[start]);
        helper(nums, target, start + 1, curr - nums[start]);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        helper(nums, target, 0, 0);
        return ans;
    }
};