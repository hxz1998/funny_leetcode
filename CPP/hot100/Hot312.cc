/*
 * Created by Xiaozhong on 3/9/2022.
 * Copyright (c) 3/9/2022 Xiaozhong. All rights reserved.
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
    int maxCoins(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j <= n + 1; ++j) {
                int mx = 0;
                for (int k = i + 1; k <= j - 1; ++k)
                    mx = max(mx, dp[i][k] + dp[k][j] +
                                 nums[i] * nums[k] * nums[j]);
                dp[i][j] = mx;
            }
        }
        return dp[0][n + 1];
    }
};

int main() {
    vector<int> nums = {3, 1, 5, 8};
    Solution s;
    cout << s.maxCoins(nums) << endl;
}