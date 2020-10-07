/**
 * Created by Xiaozhong on 2020/9/17.
 * Copyright (c) 2020/9/17 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum & 1) return false;
        int size = nums.size();
        sum /= 2;
        vector<vector<bool>> dp(size + 1, vector<bool>(sum + 1, false));

        /*
         * 基础情况
         * dp[i][j] = x：对于前 i 个物品，当前背包的容量为 j 时，
         * 若 x = true，则表示可以恰好将背包装满，否则装不满
         */
        for (int i = 0; i <= size; ++i) dp[i][0] = true;
        for (int i = 1; i <= size; ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j - nums[i - 1] < 0) {
                    // 说明背包容量装不下
                    dp[i][j] =  dp[i - 1][j];
                } else {
                    // 说明背包容量可以装得下
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[size][sum];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 5, 11, 5};
    cout << s.canPartition(nums) << endl;
    nums = {1, 2, 3, 5};
    cout << s.canPartition(nums) << endl;
    nums = {1, 3, 4, 4};
    cout << s.canPartition(nums) << endl;
    nums = {1, 2, 3, 4, 5, 6, 7};
    cout << s.canPartition(nums) << endl;
}