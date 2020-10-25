/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */
#include <cassert>
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) dp[i] = max(dp[i - 1] + 1, 1);
        }
        return dp.back();
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2};
    cout << s.lengthOfLIS(nums);
    nums = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(s.lengthOfLIS(nums) == 4);
}