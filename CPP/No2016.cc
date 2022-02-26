/**
 * Created by Xiaozhong on 2022/2/26.
 * Copyright (c) 2022/2/26 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int> &nums) {
        int ms = nums[0];
        int ans = -1;
        for (int idx = 1; idx < nums.size(); ++idx) {
            if (nums[idx] < ms) ms = nums[idx];
            else if (nums[idx] > ms) ans = max(ans, nums[idx] - ms);
        }
        return ans;
    }
};