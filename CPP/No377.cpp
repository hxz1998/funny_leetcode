/**
 * Created by Xiaozhong on 2020/9/1.
 * Copyright (c) 2020/9/1 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num :nums) {
                if (num <= i) dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    cout << s.combinationSum4(nums, 4) << endl;
}