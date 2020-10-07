/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        // 动态规划，dp[i] 代表了截止到 i ，最大的递增序列长度
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                // 状态转移方程，之所以 + 1，是因为要考虑 i 号元素
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2};
    cout << s.lengthOfLIS(nums);
}