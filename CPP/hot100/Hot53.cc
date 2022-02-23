/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = INT32_MIN, n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n + 1, 0);
        for (int idx = 0; idx < n; ++idx) {
            dp[idx + 1] = dp[idx] > 0 ? dp[idx] + nums[idx] : nums[idx];
        }
        return *max_element(dp.begin() + 1, dp.end());
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    nums = {1};
    cout << s.maxSubArray(nums) << endl;
    nums = {5, 4, -1, 7, 8};
    cout << s.maxSubArray(nums) << endl;
    nums = {-1, -2};
    cout << s.maxSubArray(nums) << endl;
}