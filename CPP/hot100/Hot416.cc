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
public:
    bool canPartition(vector<int> &nums) {
        size_t n = nums.size();
        int maxValue = 0, sumValue = 0;
        for (int num: nums) {
            maxValue = max(maxValue, num);
            sumValue += num;
        }
        if (sumValue % 2 != 0 || maxValue > sumValue / 2) return false;
        int target = sumValue / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        dp[0][nums[0]] = true;
        for (int i = 0; i < n; ++i) dp[i][0] = true;
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            for (int j = 1; j <= target; ++j) {
                if (num > j) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
            }
        }
        return dp[n - 1][target];
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 4};
    Solution s;
    nums = {2, 2, 1, 1};
    cout << s.canPartition(nums) << endl;
}