/**
 * Created by Xiaozhong on 2020/8/27.
 * Copyright (c) 2020/8/27 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    int coinChange(vector<int> &coins, int remain, vector<int> &dp) {
        if (remain < 0) return -1;
        if (remain == 0) return 0;
        if (dp[remain - 1] != 0) return dp[remain - 1];
        int ans = INT32_MAX;
        for (int coin : coins) {
            int res = coinChange(coins, remain - coin, dp);
            if (res >= 0 && res < ans) ans = res + 1;
        }
        dp[remain - 1] = (ans == INT32_MAX) ? -1 : ans;
        return dp[remain - 1];
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount);
        return coinChange(coins, amount, dp);
    }
};

int main() {
    Solution s;
    vector<int> coins = {1, 2, 5};
    cout << s.coinChange(coins, 11) << endl;
}