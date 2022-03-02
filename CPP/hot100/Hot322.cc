/*
 * Created by Xiaozhong on 3/2/2022.
 * Copyright (c) 3/2/2022 Xiaozhong. All rights reserved.
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

// 一种自己想的方法，不优雅
/*class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1);
        sort(coins.begin(), coins.end());
        if (amount < coins[0]) return amount == 0 ? 0 : -1;
        unordered_set<int> kinds;
        for (int coin: coins) kinds.insert(coin);
        for (int target = 1; target <= amount; ++target) {
            int ms = INT32_MAX;
            if (kinds.find(target) != kinds.end()) {
                dp[target] = 1;
                continue;
            }
            for (int coin: coins) {
                if (coin > target) break;
                ms = min(ms, dp[target - coin] == INT32_MAX ? INT32_MAX : dp[target - coin] + 1);
            }
            dp[target] = ms;
        }
        return dp[amount] == INT32_MAX || dp[amount] == 0 ? -1 : dp[amount];
    }
};*/

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int target = 1; target <= amount; ++target) {
            for (int coin: coins) {
                if (target - coin >= 0) dp[target] = min(dp[target], dp[target - coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    Solution s;
//    cout << s.coinChange(coins, 11) << endl;
    coins = {2};
    cout << s.coinChange(coins, 1) << endl;
}